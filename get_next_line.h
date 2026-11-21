/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindiaye <sindiaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:40:43 by sindiaye          #+#    #+#             */
/*   Updated: 2026/11/21 17:59:38 by sindiaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

#define BUFFER_SIZE 42

char *get_next_line(int fd);

#endif