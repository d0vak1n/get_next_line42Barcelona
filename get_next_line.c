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
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	
	if (!fd || fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return	(NULL);

}
