/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myavin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:52:26 by myavin            #+#    #+#             */
/*   Updated: 2019/10/27 17:56:24 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		block(int *j, char *line, char tet[][5])
{
	int	k;
	int	i;

	i = *j;
	if (i < 4)
	{
		k = 0;
		while (k < 4)
		{
			tet[i][k] = line[k];
			k++;
		}
		tet[i][k] = '\0';
	}
}

static t_list	*reader(int fd, int *t, int *j, int *i)
{
	int		count;
	char	*line;
	char	tet[4][5];
	t_list	*lst;

	count = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (valid(line, j, &count) == 0 && ((*i = -5) < 0))
			return (NULL);
		block(i, line, tet);
		if (*j % 5 == 0)
			count = 0;
		if (*i == 3)
			if ((lst = check_bl(tet, t, lst, 0)) == NULL)
				return (NULL);
		if (*i == 4)
			*i = -1;
		*i += 1;
		*j += 1;
		free(line);
	}
	return (lst);
}

int				main(int argc, char **argv)
{
	int		i;
	int		j;
	int		fd;
	int		t;
	t_list	*lst;

	i = 0;
	j = 1;
	t = 0;
	if (argc != 2)
	{
		ft_putendl("usage: fillit input_file");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (((lst = reader(fd, &t, &j, &i)) == NULL) || j % 5 != 0)
	{
		ft_putendl("error");
		return (0);
	}
	solver(lst, t, argc);
	if (argc == 2)
		close(fd);
	return (0);
}
