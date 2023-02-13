/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:07:54 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/13 21:56:23 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void bin_to_char(int sig, siginfo_t *info, void *context)
{
    static char	temp;
	static int	bit;

    (void)context;
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
        if (temp != 0)
		    write(1, &temp, 1);
        else
            kill(info->si_pid, SIGUSR1);
		bit = 0;
		temp = 0;
	}
}

int main(int ac, char *av[])
{
    struct sigaction test;
    
    (void)av;
    if (ac != 1)
        print_msg("format error is occured\n");
    print_msg("server의 pid : ");
    print_num(getpid());
    write(1, "\n", 1);
    test.sa_flags = SA_SIGINFO;
    test.sa_sigaction = bin_to_char;
    sigemptyset(&test.sa_mask);

    if (sigaction(SIGUSR1, &test, 0) == -1)
        print_msg("error is occured in receiving SIGUSR1\n");
    if (sigaction(SIGUSR2, &test, 0) == -1)
        print_msg("error is occured in receiving SIGUSR2\n");
    while (1)
        pause();
}