/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:20:27 by hvalenci          #+#    #+#             */
/*   Updated: 2019/10/27 21:04:53 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*create_map(int s)
{
	int		i;
	int		j;
	t_map	*map;

	j = 0;
	map = (t_map*)malloc(sizeof(t_map));
	map->sz = s;
	map->cnt = (char**)malloc(sizeof(char*) * s);
	while (j < s)
	{
		map->cnt[j] = ft_strnew(s);
		i = 0;
		while (i < s)
		{
			map->cnt[j][i] = '.';
			i++;
		}
		j++;
	}
	return (map);
}

void	lst_free(t_list *prev)
{
	t_list	*curr;
	t_list	*tmp;

	curr = prev->next;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	free(curr);
}

void	map_free(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->sz)
	{
		free(map->cnt[i]);
		i++;
	}
	free(map->cnt);
	free(map);
}

void	print_map(t_map *map)
{
	int	j;

	j = 0;
	while (j < map->sz)
	{
		ft_putstr(map->cnt[j]);
		ft_putchar('\n');
		j++;
	}
}
