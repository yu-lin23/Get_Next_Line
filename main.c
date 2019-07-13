/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 08:19:17 by yu-lin            #+#    #+#             */
/*   Updated: 2019/07/13 13:45:34 by yu-lin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*buffer;
	int		n;
	int		return_value;

	fd = 0;
	n = 0;
	return_value = 0;
	if (ac < 2)
	{
		ft_putendl("Too few arguments, dude!");
		return (0);
	}
	else if (ac == 2)
		fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Uhmmm...file not found, bruh");
		return (0);
	}
	while ((return_value = get_next_line(fd, &buffer)) > 0)
	{
		ft_putchar('[');
		ft_putnbr(return_value);
		ft_putstr("]-> Line[");
		ft_putnbr(n);
		ft_putstr("]	");
		ft_putendl(buffer);
		free(buffer);
		n++;
	}
	if (return_value == 0)
		ft_putendl("**********End Of File**********");
	close(fd);
	return (0);
}
