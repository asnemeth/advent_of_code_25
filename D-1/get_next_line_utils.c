/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemeth <anemeth@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:22:34 by anemeth           #+#    #+#             */
/*   Updated: 2025/10/02 18:48:45 by anemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *c)
{
	size_t	res;

	res = 0;
	while (c[res] != 0)
	{
		res++;
	}
	return (res);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t s)
{
	unsigned int	i;

	if (s == 0)
		return (ft_strlen((char *)src));
	i = 0;
	while (src[i] != 0 && i < (s - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (ft_strlen((char *)src));
}

char	*ft_strchr(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	if (c == 0)
		return ((char *)str + i);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (0);
	ptr = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (ptr == 0)
		return (0);
	i = 0;
	while (s1[i] != 0)
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = 0;
	free((void *)s1);
	return (ptr);
}

void	ft_bzero(void *ptr, size_t s)
{
	size_t	i;
	char	*p;

	if (ptr == 0)
		return ;
	i = 0;
	p = (char *)ptr;
	while (i < s)
	{
		p[i] = 0;
		i++;
	}
}
