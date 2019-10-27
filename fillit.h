/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myavin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:53:19 by myavin            #+#    #+#             */
/*   Updated: 2019/10/27 20:49:03 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE	1
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_list
{
	char			letter;
	int				height;
	int				weight;
	int				i;
	int				j;
	struct s_list	*next;
	char			cnt[4][5];
}					t_list;

typedef struct		s_map
{
	int				sz;
	int				x;
	int				y;
	char			**cnt;
}					t_map;

void				ft_bzero(void *s, size_t len);
int					valid(char *line, int *j, int *count);
void				ft_memdel(void **ap);
void				*ft_memset(void *dest, int val, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t len);
size_t				ft_strlen(const char *str);
void				ft_putchar(char c);
void				ft_strdel(char **as);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					get_next_line(const int fd, char **line);
int					check_w(char tet[][5]);
int					check_h(char tet[][5], t_list *lst);
int					valid(char *line, int *j, int *count);
void				map_free(t_map *map);
void				lst_free(t_list *prev);
void				print_map(t_map *map);
void				solver(t_list *lst, int t, int x);
int					ins_tet(t_map *map, t_list *lst, int *p, char l);
t_map				*create_map(int s);
t_list				*put_tet(char tet[][5], int *t, t_list *lst, int cont);
t_list				*check_bl(char tet[][5], int *t, t_list *lst, int cont);
#endif
