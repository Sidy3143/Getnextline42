/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindiaye <sindiaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:40:46 by sindiaye          #+#    #+#             */
/*   Updated: 2026/11/23 11:25:17 by sindiaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char    *ft_strchr(char *s, char c)
{
    int				i;
	unsigned char	my_char;

	i = 0;
	my_char = (unsigned char)c;
	while (s[i] && my_char != s[i])
		i++;
	if (my_char == s[i])
		return ((char *)(s + i));
	return (NULL);
}

char    *ft_strjoin(char *storage, char *buffer)
{
	int		i;
    char    *str;

    str = malloc(ft_strlen(storage) + ft_strlen(buffer) + 1);
	i = 0;
    while (storage[i])
	{
		str[i] = storage[i];
		i++;
	}
	i = 0;
	while (buffer[i])
	{
		str[ft_strlen(storage) + i] = buffer[i];
		i++;
	}
	str[ft_strlen(storage) + i] = '\0';
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = 0;
		p++;
		n--;
	}
}