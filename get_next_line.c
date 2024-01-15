/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrfer <sandrfer@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:17:20 by sandrfer          #+#    #+#             */
/*   Updated: 2024/01/15 13:48:39 by sandrfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_from_file(int fd)
{
	int			bytes_read;
	char		*buffer;
	static int	count;

	count = 1;
	buffer = ft_calloc((3 + 1), sizeof(char));
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

/*
int main(void)
{
	int fd;
	char *next_line;
	int	count;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break;
		count++;
		printf("[%d]:%s\n", count, next_line);
		free(next_line);
		next_line = NULL;
	}
	close(fd);
	return(0);
} */