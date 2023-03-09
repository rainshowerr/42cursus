/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:42:08 by seoshin           #+#    #+#             */
/*   Updated: 2022/08/07 20:29:50 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_c_write(va_list ap)
{
	char	buff;

	buff = (char)va_arg(ap, int);
	write(1, &buff, 1);
	return (1);
}
