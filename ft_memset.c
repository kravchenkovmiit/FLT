/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myavin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:00:46 by myavin            #+#    #+#             */
/*   Updated: 2019/10/27 17:47:57 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memset(void *dest, int val, size_t len)
{
	unsigned char *ptr;

	ptr = (unsigned char *)dest;
	while (len--)
		*ptr++ = val;
	return (dest);
}
