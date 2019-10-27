/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myavin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:02:40 by myavin            #+#    #+#             */
/*   Updated: 2019/10/27 17:47:57 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new;

	len = ft_strlen(s) + 1;
	new = (char *)malloc(sizeof(char) * len);
	if (new == NULL)
		return (NULL);
	return ((char *)ft_memcpy(new, s, len));
}
