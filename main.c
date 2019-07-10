/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 08:19:17 by yu-lin            #+#    #+#             */
/*   Updated: 2019/07/10 10:36:21 by yu-lin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*buffer;

	if (ac == 1)
		return (0);
	else if (ac == 2)
		fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &buffer) > 0)
	{
		ft_putendl(buffer);
		free(buffer);
	}
	if (ac == 2)
		close(fd);
	return (0);
}
