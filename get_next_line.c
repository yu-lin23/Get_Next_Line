/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:47:16 by yu-lin            #+#    #+#             */
/*   Updated: 2019/07/02 17:08:36 by yu-lin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*ft_strsub(char const *s, unsigned int start, size_t len);

/*With 2D array*/
static int	read_line(int fd, char **buffer, int buffer_size)
{
	char *placeholder;
	char temp[BUFF_SIZE + 1];
	ssize_t len;

	len = read(fd, temp, BUFF_SIZE);
	temp[len] = '\0';
	placeholder = ft_strjoin(*buffer, buffer_size);
	free(*temp);
	free(newl);
	return (len);
}

/*With linked lists
static t_list *get_file(int fd, t_list **file)
{
	t_list *temp;

	temp = *file;
	while (temp)
	{
		if ((int)temp->content_size == fd) //What does this mean?
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("\0", fd);
	ft_lstadd(file, temp);
	return (temp);
}*/
int		get_next_line(const int fd, char **line)
{
	static char *temp;
	char *count;
	int error;

	temp = NULL;
	if (temp == NULL)
		temp = (char *)malloc(sizeof(char));
	while (ft_strchr(temp, '\n') == NULL)
	{
		error = read(fd, &temp);
		if (error == 0)
			return (0);
		else if (error == -1)
			return (-1);
	}
	*line = ft_strsub(temp, 0, ft_strchr(temp, '\n'));
	count = ft_strchr(temp, '\n');
	count++;
	free(temp);
	temp = ft_strdup(count);
	return (1);
}

int		main(int ac, char **av)
{
	int fd;
	char *buffer;

	buffer = (char *)malloc(sizeof(char) * 1024);
	fd = open(ac[1], O_RDONLY);
	get_next_line(fd, &buffer);
	return (0);
}
