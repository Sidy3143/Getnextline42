/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindiaye <sindiaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:39:17 by sindiaye          #+#    #+#             */
/*   Updated: 2026/11/21 18:33:31 by sindiaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static  char    *storage;
    char    *line;
    
    if (fd < 0 || BUFFER_SIZE == 0)
        return (NULL);
    storage = read_and_store(fd, storage);
    line = extract_line(storage);
    
}

char    *read_and_store(int fd, char *storage)
{
    size_t  bytes_read;
    char    *buffer;

    bytes_read = 1;
    buffer = malloc(BUFFER_SIZE + 1);
    while(!ft_strchr(storage, '\n') && bytes_read > 0)
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
        ft_bzero(buffer);
    }
    return (storage);
}

char    *ft_strjoin(char *storage, char *buffer)
{
    
}

char    *extract_line(char **storage)
{
    int     i;
    char    *line;

    i = 0;
    while((*storage)[i] && (*storage)[i] != '\n')
        i++;
    line = malloc(i + 1);
    i = 0;
    while((*storage)[i] && (*storage)[i] != '\n')
    {
        line[i] = (*storage)[i];
        i++;
    }
    *storage = (*storage) + i;
    return (line);
}
