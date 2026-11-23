/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindiaye <sindiaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:40:46 by sindiaye          #+#    #+#             */
/*   Updated: 2026/11/23 14:25:23 by sindiaye         ###   ########.fr       */
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

char	*ft_strchr(char *s, char c)
{
	int				i;
	unsigned char	my_char;

	i = 0;
	if (!s)
		return (NULL);
	my_char = (unsigned char)c;
	while (s[i] && my_char != s[i])
		i++;
	if (my_char == s[i])
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char *storage, char *buffer)
{
	int		i;
	char	*str;

	if (!storage)
		storage = ft_strdup("");
	str = malloc(ft_strlen(storage) + ft_strlen(buffer) + 1);
	if (!str)
		return (NULL);
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
	free(storage);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = 0;
	while (s[s_len])
		s_len++;
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while ((i < len) && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
