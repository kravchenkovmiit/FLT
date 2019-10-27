/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:20:08 by hvalenci          #+#    #+#             */
/*   Updated: 2019/10/27 17:33:29 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_h(char tet[][5], t_list *lst)
{
	int	i;
	int	j;
	int	min;
	int	max;

	j = -1;
	min = 4;
	max = 1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
		{
			if (tet[j][i] == '#')
			{
				lst->i = i;
				lst->j = j;
				if ((j + 1) < min)
					min = j + 1;
			}
			else if (tet[j][i] == '#' && (j + 1) > max)
				max = j + 1;
		}
	}
	return (max - min + 1);
}

int		check_w(char tet[][5])
{
	int	i;
	int	j;
	int	min;
	int	max;

	j = 0;
	min = 4;
	max = 1;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tet[j][i] == '#' && (i + 1) < min)
				min = i + 1;
			else if (tet[j][i] == '#' && (i + 1) > max)
				max = i + 1;
			i++;
		}
		j++;
	}
	return (max - min + 1);
}

t_list	*check_bl(char tet[][5], int *t, t_list *lst, int cont)
{
	int	j;
	int	i;

	j = -1;
	while (++j < 4 && (i = -1) < 0)
	{
		while (++i < 4)
		{
			if (tet[j][i] == '#')
			{
				if (i > 0 && tet[j][i - 1] == '#')
					cont++;
				if (i < 3 && tet[j][i + 1] == '#')
					cont++;
				if (j > 0 && tet[j - 1][i] == '#')
					cont++;
				if (j < 3 && tet[j + 1][i] == '#')
					cont++;
			}
		}
	}
	return (lst = put_tet(tet, t, lst, cont));
}

int		valid(char *line, int *j, int *count)
{
	int	i;

	i = 0;
	if ((*j % 5 != 0) && ft_strlen(line) != 4)
		return (0);
	if (*j > 130)
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] == '#')
			*count += 1;
		if (line[i] != '.' && line[i] != '#')
			return (0);
		if (*count > 4 || (i == 3 && *j == 4 && *count != 4))
			return (0);
		i++;
	}
	return (1);
}
