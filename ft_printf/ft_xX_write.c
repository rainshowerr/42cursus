/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:42:28 by seoshin           #+#    #+#             */
/*   Updated: 2022/08/07 21:00:04 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_xx_write(int c, va_list ap)
{
	unsigned long long	tmp;

	tmp = (unsigned long long)va_arg(ap, int);
	if (c == 'x')
		return (ft_hexadec(tmp, "0123456789abcdef"));
	if (c == 'X')
		return (ft_hexadec(tmp, "0123456789ABCDEF"));
	return (0);
}
