/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:47:16 by yu-lin            #+#    #+#             */
/*   Updated: 2019/07/09 15:07:43 by yu-lin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_line(int fd, char **tmp_buffer)
{
	char	buffer[BUFF_SIZE + 1];
	char 	*holder;
	size_t size;

	size = read(fd, buffer, BUFF_SIZE);
	buffer[size] = '\0';
	holder = ft_strjoin(tmp_buffer[fd], buffer);
	ft_strdel(&tmp_buffer[fd]);
	tmp_buffer[fd] = ft_strdup(holder);
	ft_strdel(&holder);
	return (size);
}

int		from_where(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

int		ft_putline(char **str, char **line, int fd, int result)
{
	char *placeholder;
	size_t i;

	i = from_where(str[fd]);
	if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		placeholder = ft_strdup(str[fd] + i + 1);
		ft_strdel(&str[fd]);
		str[fd] = placeholder;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][i] == '\0')
	{
		if (result == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char *tmp_buffer[1024];
	int result;

	if (tmp_buffer[fd] == NULL)
		tmp_buffer[fd] = (char*)ft_memalloc(sizeof(char));
	while (ft_strchr(tmp_buffer[fd], '\n') == NULL)
	{
		result = read_line(fd, tmp_buffer);
		if (result < 0)
			return (-1);
		else if (result == 0 && (tmp_buffer[fd] == NULL || tmp_buffer[fd][0] == '\0'))
			return (0);
	}
	return (ft_putline(tmp_buffer, line, fd, result));
}

int		main(int ac, char **av)
{
	int fd;
	char *buffer = (char *)malloc(sizeof(char) * 1024);

	if (ac == 1)
		return (0);
	else if (ac == 2)
		fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &buffer)	> 0)
	{
		ft_putendl(buffer);
		free(buffer);
	}
	if (ac == 2)
		close(fd);
	return (0);
}
