/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:44:18 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/10 20:44:18 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t ft_space(int n)
{
    size_t space;

    n = (long long)n;
    if (n == 0)
        return 1;
    space = 0;
    if (n < 0)
    {
        space++;
        n *= -1;
    }
    while(n)
    {
        n /= 10;
        space++;
    }
    return space;
}

char *ft_itoa(int n)
{
    char    *ans;
    int     idx;

    n = (long long)n;
    if (!(ans = (char *)malloc(sizeof(char) * (ft_space(n) + 1))))
        return (0);
    idx = ft_space(n);
    ans[idx--] = '\0';
    if (n == 0)
        ans[idx] = '0';
    else if (n < 0)
    {
        ans[0] = '-';
        n *= -1;
    }
    while(n)
    {
        ans[idx--] = (n % 10) + '0';
        n /= 10;
    }
    return ans;
}