/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:58:44 by ramoreno          #+#    #+#             */
/*   Updated: 2024/04/03 13:59:02 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*_fill_line(char *buffer, int fd, char *overbuffer);
static char	*_set_line(char *line);

char	*get_next_line(int fd)
{
	static char	*overbuffer;
	char		*buffer;
	char		*line;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!fd || fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = _fill_line(buffer, fd, overbuffer);
	free(buffer);
	if (!line)
		return (NULL);
	overbuffer = _set_line(line);
	return (line);
}

static char	*_fill_line(char *buffer, int fd, char *overbuffer)
{
	ssize_t	bytesread;
	char	*temp;

	bytesread = 1;
	while (bytesread != (0 | -1))
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
			break ;
		else if (bytesread == 0)
			break ;
		buffer[bytesread] = '\0';
		if (!overbuffer)
			overbuffer = ft_strdup("");
		temp = overbuffer;
		overbuffer = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (overbuffer);
}

static char	*_set_line(char *line)
{
	char	*overbuffer;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[i] == '\0')
		return (NULL);
	overbuffer = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*overbuffer == '\0')
	{
		free(overbuffer);
		overbuffer = NULL;
	}
	line[i + 1] = '\0';
	return (overbuffer);
}

ssize_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (src != NULL)
	{
		len = ft_strlen(src);
		if (dst != NULL && dstsize != 0)
		{
			while (i < len && i < (dstsize - 1))
			{
				dst[i] = src[i];
				i++;
			}
			dst[i] = '\0';
		}
	}
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	ft_strlcat(res, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (res);
}
