/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindiaye <sindiaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:40:46 by sindiaye          #+#    #+#             */
/*   Updated: 2026/11/21 17:45:53 by sindiaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char    *ft_strjoin(char *s1, char *s2)
{
    
}
