/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:47:16 by yu-lin            #+#    #+#             */
/*   Updated: 2019/07/03 17:16:57 by yu-lin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*With 2D array
static int	read_line(int fd, char **buffer, int buffer_size)
{
	char *holder;
	char temp[BUFF_SIZE + 1];
	ssize_t size;

	size = read(fd, temp, buffer_size);
	if (size < 1) //if it is an error or output
		return (size);//the last line
	temp[size] = '\0';
	holder = ft_strjoin(*buffer, temp);
	free(*buffer);
	*buffer = ft_strdup(holder);
	return (1);
}

static char	find_new_line(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char *tmp_buffer;
	int error;

	tmp_buffer = NULL;
	if (tmp_buffer == NULL)
		tmp_buffer = (char *)malloc(sizeof(char));
	while (ft_strchr(tmp_buffer, '\n') == NULL)
	{
		error = read_line(fd, &tmp_buffer, BUFF_SIZE);
		if (error == 0)
			return (0);
		else if (error == -1)
			return (-1);
	}
	*line = ft_strsub(tmp_buffer, 0, find_new_line(tmp_buffer));
	tmp_buffer = ft_strchr(tmp_buffer, '\n');
	tmp_buffer++;
	return (1);
}*/

char		*join(char *s1, char *s2)
{
	size_t size;
	char *newstr;

	size = strlen(s1) + strlen(s2);
	newstr = (char *)malloc(sizeof(char) * size + 1);
	strcpy(newstr, s1);
	strcst(newstr, s2);
	newstr[size] = '\0';
	return (newstr);
}

int		read_chunk(int fd, char **buffer, int buffer_size)
{
	char *holder;
	char temp_buffer[buffer_size + 1];
	ssize_t size;

	size = read(fd. temp_buffer, buffer_size);
	if (size < 1)
		return (size);
	temp_buffer[size] = '\0';
	holder = join(*buffer, temp_buffer);
	free(*buffer);
	*buffer = strdup(holder);
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

char	*substr(char *str, int start, int len)
{
	char *newstr;
	int i;

	newstr = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	while (i < len)
	{
		newstr[i] = str[start];
		i++;
		start++;
	}
	newstr[i] = '\0';
	return (newstr);
}

int		get_next_line(iiint fd, char **line)
{
	static char *buffer = NULL;
	int error;

	if (buffer == NULL)
		buffer = (char *)malloc(sizeof(char));
	while (strchr(buffer, '\n') == NULL)
	{
		error = read_line(fd, &buffer, BUFF_SIZE);
		if (error < 1)
			return (error);
	}
	*line = substr(buffer, 0, from_where(buffer, '\n'));
	bufer = strchr(buffer, '\n');
	buffer++;
	return (1);
}
int		main(int ac, char **av)
{
	int fd;
	char *buffer;
	int i;

	if (ac == 2)
	{
		i = 0;
		fd = open(av[1], O_RDONLY);
		while ((get_next_line(fd, &buffer)) == 1)
		{
			ft_putstr(buffer);
			ft_putchar('\n');
		}
		close(fd);
	}
	return (0);
}
