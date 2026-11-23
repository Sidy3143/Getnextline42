/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindiaye <sindiaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:39:17 by sindiaye          #+#    #+#             */
/*   Updated: 2026/11/23 14:24:56 by sindiaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	storage = read_and_store(fd, storage);
	line = extract_line(&storage);
	return (line);
}

char	*read_and_store(int fd, char *storage)
{
	ssize_t	bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	while (!ft_strchr(storage, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(storage);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
		ft_bzero(buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (storage);
}

char	*extract_line(char **storage)
{
	int		i;
	char	*line;
	char	*new_storage;

	if (!(*storage) || !(**storage))
		return (NULL);
	i = 0;
	while ((*storage)[i] && (*storage)[i] != '\n')
		i++;
	line = malloc(i + 1);
	line = ft_substr(*storage, 0, i + 1);
	new_storage = ft_substr(*storage, i + 1, ft_strlen(*storage) - (i + 1));
	free(*storage);
	*storage = new_storage;
	return (line);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;
	size_t	i;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			perror("open");
			return (1);
		}
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	if (fd > 0)
		close(fd);
	return (0);
}
*/