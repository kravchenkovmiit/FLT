/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myavin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:56:36 by myavin            #+#    #+#             */
/*   Updated: 2019/10/27 17:47:57 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = ft_strnew(s1_len + s2_len);
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < s1_len)
		*(str + i) = *(s1 + i);
	while (++j < s2_len)
		*(str + i++) = *(s2 + j);
	return (str);
}
