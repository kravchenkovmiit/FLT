/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:37:05 by hvalenci          #+#    #+#             */
/*   Updated: 2019/10/27 17:37:39 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_list	*new_tet(char tet[][5])
{
	int		i;
	int		j;
	t_list	*lst;

	j = 0;
	lst = (t_list*)malloc(sizeof(t_list));
	while (j < 4)
	{
		i = 0;
		while (i < 5)
		{
			lst->cnt[j][i] = tet[j][i];
			i++;
		}
		j++;
	}
	lst->letter = 'A';
	lst->height = check_h(tet, lst);
	lst->weight = check_w(tet);
	lst->next = NULL;
	return (lst);
}

static t_list	*add_tet(t_list *prev, char tet[][5], int *t)
{
	int		i;
	int		j;
	t_list	*lst;
	t_list	*tmp;

	j = -1;
	tmp = prev;
	lst = (t_list*)malloc(sizeof(t_list));
	while (++j < 4)
	{
		i = -1;
		while (++i < 5)
			lst->cnt[j][i] = tet[j][i];
	}
	lst->letter = 'A' + *t;
	lst->height = check_h(tet, lst);
	lst->weight = check_w(tet);
	while (prev->next != NULL)
		prev = prev->next;
	lst->next = NULL;
	prev->next = lst;
	return (tmp);
}

t_list			*put_tet(char tet[][5], int *t, t_list *lst, int cont)
{
	if (cont < 5)
		return (NULL);
	if (*t == 0)
	{
		lst = new_tet(tet);
		*t = 1;
	}
	else
	{
		lst = add_tet(lst, tet, t);
		*t += 1;
	}
	return (lst);
}
