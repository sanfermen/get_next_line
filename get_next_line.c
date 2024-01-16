/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrfer <sandrfer@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:17:20 by sandrfer          #+#    #+#             */
/*   Updated: 2024/01/16 18:59:11 by sandrfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*clean(char *newline)
{
	char	*new;
	char	*ptr;
	int		len;

	ptr = ft_strchr(newline, '\n');
	if (!ptr)
	{
		new = NULL;
		return (ft_free(&newline));
	}
	else
		len = (ptr - newline) + 1;
	if (!newline[len])
		return (ft_free(&newline));
	new = ft_substr(newline, len, ft_strlen(newline) - len);
	ft_free(&newline);
	if (!new)
		return (NULL);
	return (new);
}

char	*get_newline(char *newline)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(newline, '\n');
	len = (ptr - newline) + 1;
	line = ft_substr(newline, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_file(int fd, char *str)
{
	int		count;
	char	*buffer;

	count = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&str));
	buffer[0] = '\0';
	while (count > 0 && !ft_strchr(buffer, '\n'))
	{
		count = read (fd, buffer, BUFFER_SIZE);
		if (count > 0)
		{
			buffer[count] = '\0';
			str = ft_strjoin(str, buffer);
		}
	}
	free(buffer);
	if (count == -1)
		return (ft_free(&str));
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str = {0};
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((str && !ft_strchr(str, '\n')) || !str)
		str = read_file (fd, str);
	if (!str)
		return (NULL);
	line = get_newline(str);
	if (!line)
		return (ft_free(&str));
	str = clean(str);
	return (line);
}
