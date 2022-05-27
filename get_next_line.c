/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afridasufi <afridasufi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 13:14:12 by afridasufi        #+#    #+#             */
/*   Updated: 2021/10/16 14:15:21 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_nl(const char *s)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (*p != '\0' && *p != '\n')
	{
		i++;
		p++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_x;
	size_t	len_y;

	str = ((char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!str)
		return (NULL);
	len_x = 0;
	len_y = 0;
	while (s1[len_x])
	{
		str[len_y++] = s1[len_x];
		len_x++;
	}
	len_x = 0;
	while (s2[len_x])
	{
		str[len_y++] = s2[len_x];
		len_x++;
	}
	str[len_y] = '\0';
	return (str);
}

int	ft_strlen(const char *s)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (*p != '\0')
	{
		i++;
		p++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = (char)c;
	if (*s == i)
		return ((char *)s);
	while (*s != i && *s != '\0')
	{
		s++;
		if (*s == i)
			return ((char *)s);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buff[MAX_FD][BUFFER_SIZE + 1];
	char		*new_line;
	int			read_line;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1 )
		return (NULL);
	new_line = (char *)malloc(1);
	new_line[0] = 0;
	while (!ft_strchr(buff[fd], '\n'))
	{
		if (*buff[fd])
			new_line = set_line(buff[fd], &new_line);
		read_line = read(fd, buff[fd], BUFFER_SIZE);
		buff[fd][read_line] = '\0';
		if (read_line <= 0 && !*new_line)
		{
			ft_free (new_line);
			return (NULL);
		}
		if ((read_line < BUFFER_SIZE && (ft_strchr(buff[fd], '\n') == NULL)))
			return ((set_line(buff[fd], &new_line)));
	}
	return ((set_n_return(buff[fd], &new_line)));
}
