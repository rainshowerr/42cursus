/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:07:49 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/14 20:16:30 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	bin_to_char(int sig)
{
	static char	temp;
	static int	bit;

	if (sig == SIGUSR1 && bit < 8)
		temp <<= 1;
	else if (sig == SIGUSR2 && bit < 8)
	{
		temp <<= 1;
		temp |= 1;
	}
	bit++;
	if (bit == 8)
	{
		write(1, &temp, 1);
		bit = 0;
		temp = 0;
	}
}

int	main(int ac, char *av[])
{
	(void)av;
	if (ac != 1)
	{
		print_msg("format error is occured\n");
		exit(1);
	}
	print_msg("server's pid : ");
	print_num(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, bin_to_char);
	signal(SIGUSR2, bin_to_char);
	while (1)
		pause();
}
