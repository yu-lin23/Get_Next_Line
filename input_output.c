/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 08:27:12 by yu-lin            #+#    #+#             */
/*   Updated: 2019/07/07 11:18:49 by yu-lin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#define BUFF_SIZE 8

int main(void)
{
	char *holder;
	char str[BUFF_SIZE + 1];
	int fd;
	int size;

	fd = open("nyan.txt", O_RDONLY, 0);
	size = read(fd, str, BUFF_SIZE);
	printf("fd = %d\n", fd);
	printf("size = %d\n", size);
	printf("str = %s\n", str);

	//printf("while str = %s\n", str);
	return (0);
}
