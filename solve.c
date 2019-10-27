/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:20:56 by hvalenci          #+#    #+#             */
/*   Updated: 2019/10/27 20:54:39 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	move_nmove(t_map *map, t_list *lst, int *p, char l)
{
	if (lst->cnt[(p[4])][(p[3])] == '#')
	{
		if (p[5] == 0 && (p[6] = p[3]) >= -1)
			p[7] = p[4];
		if ((p[1] + p[4] - p[7] < map->sz) && (p[0] + p[3] - p[6] < map->sz))
		{
			if (map->cnt[(p[1] + p[4] - p[7])][(p[0] + p[3] - p[6])] == '.' \
					|| map->cnt[(p[1] + p[4] - p[7])][(p[0] + p[3] - p[6])] \
					== lst->letter)
			{
				p[5]++;
				if (p[2])
					map->cnt[(p[1] + p[4] - p[7])][(p[0] + p[3] - p[6])] = l;
			}
		}
		if (p[5] == 4)
		{
			if (p[2])
				return (1);
			p[2] = 1;
			return (ins_tet(map, lst, p, l));
		}
	}
	return (0);
}

int			ins_tet(t_map *map, t_list *lst, int *p, char l)
{
	p[4] = -1;
	p[5] = 0;
	while (++p[4] < 4)
	{
		p[3] = -1;
		while (++p[3] < 4)
		{
			if (move_nmove(map, lst, p, l))
				return (1);
		}
	}
	return (0);
}

static int	insert_tet(t_map *map, t_list *lst)
{
	int		par[8];
	t_list	*p;

	p = lst;
	par[1] = -1;
	if (p == NULL)
		return (1);
	while (++par[1] < map->sz)
	{
		par[0] = -1;
		while (++par[0] < map->sz)
		{
			par[2] = 0;
			if (map->cnt[(par[1])][(par[0])] == '.')
				if (ins_tet(map, p, par, p->letter))
				{
					if (insert_tet(map, lst->next))
						return (1);
					else if ((par[2] = 1))
						ins_tet(map, p, par, '.');
				}
		}
	}
	return (0);
}

void		solver(t_list *lst, int t, int size)
{
	t_map	*map;

	while (size * size < t * 4)
		size++;
	map = create_map(size);
	while (!(insert_tet(map, lst)))
	{
		size++;
		map_free(map);
		map = create_map(size);
	}
	print_map(map);
	map_free(map);
	lst_free(lst);
}
