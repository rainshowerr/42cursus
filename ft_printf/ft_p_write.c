/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:41:27 by seoshin           #+#    #+#             */
/*   Updated: 2022/08/07 20:13:53 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_p_write(va_list ap)
{
	unsigned long long	address;

	address = (unsigned long long)va_arg(ap, void *);
	write(1, "0x", 2);
	return (ft_hexadec(address, "0123456789abcdef") + 2);
}
