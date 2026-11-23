/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindiaye <sindiaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:40:43 by sindiaye          #+#    #+#             */
/*   Updated: 2026/11/23 11:41:46 by sindiaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char *get_next_line(int fd);
char    *read_and_store(int fd, char *storage);
char    *extract_line(char **storage);

char    *ft_strchr(char *s, char c);
char    *ft_strjoin(char *storage, char *buffer);
void	ft_bzero(void *s, size_t n);
int	ft_strlen(char *str);

#endif