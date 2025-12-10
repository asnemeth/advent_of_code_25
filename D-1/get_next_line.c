/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemeth <anemeth@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:10:27 by anemeth           #+#    #+#             */
/*   Updated: 2025/10/02 19:23:10 by anemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	buffclear(char **buffer)
{
	free(*buffer);
	*buffer = 0;
}

static char	*newlinelert(char *buffer, char *res)
{
	char	*newline;
	size_t	diff;
	char	*temp;

	newline = ft_strchr(buffer, 10);
	diff = ft_strlen(buffer) - (ft_strlen(newline) - 1);
	temp = (char *)malloc((diff + 1) * sizeof(char));
	ft_strlcpy(temp, buffer, diff + 1);
	res = ft_strjoin(res, temp);
	free(temp);
	ft_strlcpy(buffer, &buffer[diff], BUFFER_SIZE - diff + 1);
	ft_bzero(&buffer[BUFFER_SIZE - diff], diff);
	return (res);
}

static int	readcheck(char **res, char **buffer, int c, int fd)
{
	*res = ft_strjoin(*res, *buffer);
	c = read(fd, *buffer, BUFFER_SIZE);
	if (c <= 0)
		return (1);
	if (c < BUFFER_SIZE)
		ft_bzero(*buffer + c, BUFFER_SIZE - c);
	return (0);
}

static char	*getter(int fd, char *buffer)
{
	char	*res;
	int		c;

	res = (char *)malloc(1 * sizeof(char));
	if (res == 0)
		return (0);
	res[0] = 0;
	if (buffer[0] == 0)
	{
		c = read(fd, buffer, BUFFER_SIZE);
		if (c <= 0)
		{
			free(res);
			return (0);
		}
	}
	while (ft_strchr(buffer, 10) == 0 && buffer[0] != 0)
		if (readcheck(&res, &buffer, c, fd) != 0)
			break ;
	if (ft_strchr(buffer, 10) != 0)
		res = newlinelert(buffer, res);
	else
		ft_bzero(buffer, BUFFER_SIZE);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (buffer == 0)
	{
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == 0)
			return (0);
		ft_bzero(buffer, BUFFER_SIZE + 1);
	}
	res = getter(fd, buffer);
	if (res == 0)
	{
		buffclear(&buffer);
		return (0);
	}
	return (res);
}
