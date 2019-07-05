/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:47:16 by yu-lin            #+#    #+#             */
/*   Updated: 2019/07/05 23:52:49 by yu-lin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>

int		read_line(int fd, char **buffer, int buff_size)
{
	char *holder;
	char tmp_buffer[BUFF_SIZE + 1];
	ssize_t size;

	size = read(fd, tmp_buffer, BUFF_SIZE);
	tmp_buffer[size] = '\0';
	holder = ft_strjoin(*buffer, tmp_buffer);
	free(*buffer);
	*buffer = ft_strdup(holder);
	free(holder);
	return (1);
}

int		from_where(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static char *tmp_buffer = NULL;
	int error;

	if (tmp_buffer == NULL)
		tmp_buffer = (char*)ft_memalloc(sizeof(char));
	while (ft_strchr(tmp_buffer, '\n') == NULL)
	{
		error = read_line(fd, &tmp_buffer, BUFF_SIZE);
		if (error == 0)
			return (0);
		else if (error == -1)
			return (-1);
	}
	*line = ft_strsub(tmp_buffer, 0, from_where(tmp_buffer, '\n'));
	tmp_buffer = ft_strchr(tmp_buffer, '\n');
	tmp_buffer++;
	return (1);
}

int		main(int ac, char **av)
{
	int fd;
	int i;
	char *buffer;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		i = get_next_line(fd, &buffer);
		while (i > 0)
		{
			printf("%s\n", buffer);
		}
	}
	return (0);
}
