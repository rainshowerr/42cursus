/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:08:04 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/13 21:56:58 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

void handler(int sig)
{
    if (sig == SIGUSR1)
        print_msg("signal received well\n");
    exit(0);
}

void bin_to_send(int pid, int bit)
{
    if (bit == 0)
        kill(pid, SIGUSR1);
    else if (bit == 1)
        kill(pid, SIGUSR2);
    usleep(100);
}

void ten_to_bin(int pid, char c)
{
    int bit;

    bit = 0;
    while (bit < 8)
    {
        bin_to_send(pid, c >> (7 - bit) & 1);
        bit++;
    }
}

void    str_to_ten(int  pid, char *string)
{
    int i;

    i = 0;
    while (string[i])
    {
        ten_to_bin(pid, string[i]);
        i++;
    }
    ten_to_bin(pid, 10);
    ten_to_bin(pid, 0);
}

int main(int ac, char **av)
{
    if (ac != 3 || ft_atoi(av[1]) <= 100 || 100000 <= ft_atoi(av[1]))
    {
        print_msg("error\n");
        exit(1);
    }
    else
    {
        signal(SIGUSR1, handler);
        str_to_ten(atoi(av[1]), av[2]);
    }
    while (1)
        pause();
}