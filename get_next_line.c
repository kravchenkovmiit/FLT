/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myavin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:21:08 by myavin            #+#    #+#             */
/*   Updated: 2019/10/27 17:54:24 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	fill_line(int fd, int n, char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		tmp = ft_strdup(&s[fd][len + 1]);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][len] == '\0')
	{
		if (n == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*s[255];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			n;

	if (fd < 0 || !line)
		return (-1);
	while ((n = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[n] = '\0';
		if (!s[fd])
			s[fd] = ft_strnew(0);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (n < 0)
		return (-1);
	else if (n == 0 && !s[fd])
		return (0);
	return (fill_line(fd, n, s, line));
}
