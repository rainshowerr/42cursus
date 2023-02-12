/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:53:59 by coh               #+#    #+#             */
/*   Updated: 2023/02/09 23:02:42 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

void handler(int sig)
{
    if (sig == SIGUSR1)
        printf("signal received well\n");
    exit(0);
}

void bin_to_send(int pid, int bit)
{
    if (bit == 0)
    {
        write(1, "0", 1);
        kill(pid, SIGUSR1);
    }
    else if (bit == 1)
    {
        write(1, "1", 1);
        kill(pid, SIGUSR2);
    }
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
    if (ac != 3)
    {
        printf("usage : ./a.out [server's pid] \"[string]\"\n");
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