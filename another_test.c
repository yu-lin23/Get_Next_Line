/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 10:58:06 by yu-lin            #+#    #+#             */
/*   Updated: 2019/07/07 13:28:50 by yu-lin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

#define BUFF_SIZE 8

int main(void)
{
	static char *holder = NULL;
	char buffer[BUFF_SIZE + 1];
	int fd;
	int size;
	int i;

	if (!holder)
		holder =(char*)malloc(sizeof(char));
	fd = open("nyan.txt", O_RDONLY, 0);
	size = read(fd, buffer, BUFF_SIZE);
	printf("buffer = %s\n", buffer);
	i = 0;
	while (i < size)
	{
		*holder = *ft_strjoin(holder, &buffer[i]);
		printf("holder = %s\n", holder);
		if (buffer[i] == 't')
				break;
		holder++;
		i++;
	}
	//printf("buffer[fd] = %c\n", buffer[fd]);
	//printf("holder[size] = %c\n", holder[size]);

}
/*
>>buffer = First li
>>holder = F
>>holder = i
>>holder = r
>>holder = s
>>holder = t
*/
