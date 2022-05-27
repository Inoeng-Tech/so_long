/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afridasufi <afridasufi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:22:39 by afridasufi        #+#    #+#             */
/*   Updated: 2021/10/16 14:14:18 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
* Helper function file which is needed for Get_next_line.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	ptr = (char *)malloc(sizeof(*s) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			ptr[j] = s[i];
			j++;
		}
		i++;
	}
	ptr[j] = 0;
	return (ptr);
}

void	ft_free(char *ptr)
{
	free (ptr);
	ptr = NULL;
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		len;

	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while ((i < (dstsize - 1)) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

char	*set_n_return(char *buff, char **line)
{
	char	*temp;

	if (!*(*line))
	{
		ft_free (*line);
		*line = ft_substr(buff, 0, ft_strlen_nl(buff) + 1);
		temp = ft_substr(buff, ft_strlen_nl(buff) + 1, (ft_strlen(buff) - \
				ft_strlen_nl(buff)));
		ft_strlcpy(buff, temp, ft_strlen(buff));
		ft_free (temp);
		return (*line);
	}
	else
	{
		temp = ft_strjoin(*line, buff);
		ft_free (*line);
		*line = ft_substr(temp, 0, ft_strlen_nl(temp) + 1);
		ft_free (temp);
		temp = ft_substr(buff, ft_strlen_nl(buff) + 1, (ft_strlen(buff) - \
				ft_strlen_nl(buff)));
		ft_strlcpy(buff, temp, ft_strlen(buff));
		ft_free (temp);
		return (*line);
	}
}

char	*set_line(char *buff, char **line)
{
	char	*temp;

	temp = ft_strjoin(*line, buff);
	ft_free (*line);
	buff[0] = '\0';
	return (temp);
}
