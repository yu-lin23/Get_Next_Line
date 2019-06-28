/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:47:16 by yu-lin            #+#    #+#             */
/*   Updated: 2019/06/28 11:27:46 by yu-lin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*With 2D array*/
static int	read_line(int fd, char **temp)
{
	char line[BUFF_SIZE + 1];
	size_t len;
	char *newl;

	len = read(fd, line, BUFF_SIZE);
	line[len] = '\0';
	newl = ft_strjoin(*temp, line);
	free(*temp);
	free(newl);
	return (len);
}

/*With linked lists
static t_list *get_file(t_list **file, int fd)
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
	return (temp);*/
}
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
