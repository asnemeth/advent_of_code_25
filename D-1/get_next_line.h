/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemeth <anemeth@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:11:33 by anemeth           #+#    #+#             */
/*   Updated: 2025/10/02 18:47:50 by anemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *c);
size_t	ft_strlcpy(char *dest, const char *src, size_t s);
char	*ft_strchr(const char *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *ptr, size_t s);

#endif
