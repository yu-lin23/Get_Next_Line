/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 08:27:12 by yu-lin            #+#    #+#             */
/*   Updated: 2019/07/02 17:08:40 by yu-lin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
extern int errno;

int main(void)
{
	char str[100];
	ssize_t size;
	int fd1 = open("nyan.txt", O_RDONLY, 0);
	int fd2 = open("meow.txt", O_RDONLY, 0);
	size = read(fd1, &str, 12);
	read(fd1, &str, 12);
	printf("size = %d", size);
	printf("str = %s", str);
	return (0);
}
