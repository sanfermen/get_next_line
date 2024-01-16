/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrfer <sandrfer@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:17:20 by sandrfer          #+#    #+#             */
/*   Updated: 2024/01/16 11:35:02 by sandrfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*clean_newline(char *newline)
{
	char	*clean;
	char	*ptr;
	int		len;

	ptr = ft_strchr(newline, '\n');
	if (!ptr)
	{
		clean = NULL;
		return (ft_free(&newline));
	}
	else
		len = (ptr - newline) + 1;
	if (!newline[len])
		return (ft_free(&newline));
	clean = ft_substr(newline, len, ft_strlen(newline) - len);
	ft_free(&newline);
	if (!clean)
		return (NULL);
	return (clean);
}

char	*get_newline(char *newline)
{
	char	*ptr;
	char	*line;
	int		len;

	ptr = ft_strchr(newline, '\n');
	len = (ptr - newline) + 1;
	line = ft_substr(newline, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_from_file(int fd)
{
	int			bytes_read;
	char		*buffer;
	static int	count;

	count = 1;
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, 3);
	// Hay que decirle al código cuándo parar: cuando lea 0 menos bytes
	if (bytes_read <= 0)
	{
		free (buffer);
		return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*gnl_buffer;

	gnl_buffer = read_from_file(fd);
	return (gnl_buffer);
}
