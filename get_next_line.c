/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:47:16 by yu-lin            #+#    #+#             */
/*   Updated: 2019/07/07 13:31:14 by yu-lin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	static char *tmp_buffer = NULL;
	char buffer[BUFF_SIZE + 1];
	int error;

	if (!tmp_buffer)
		tmp_buffer = (char*)ft_memalloc(sizeof(char));
	while ((red = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[red] = '\0';
		holder = ft_strjoin(holder, buffer);
		if (holder == '\n')
			break;
	}
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
