/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:47:38 by marvin            #+#    #+#             */
/*   Updated: 2022/07/10 16:47:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void ft_putn_fd(int n, int fd)
{
    char c;
    c = n + '0';
    write(fd, &c, 1);
}

void ft_putnbr_fd(int n, int fd)
{
    if (n == -2147483648)
        write(fd, "-2147483648", 11);
    else if (n < 0)
    {
        write(fd, "-", 1);
        n *= -1;
        ft_putnbr_fd(n, fd);
    }
    else if (n <= 9)
    {
        ft_putn_fd(n, fd);
    }
    else
    {
        ft_putnbr_fd(n / 10, fd);
        ft_putn_fd(n % 10, fd);
    }
}