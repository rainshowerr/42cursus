/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:14:20 by seoshin           #+#    #+#             */
/*   Updated: 2022/08/07 20:36:23 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_s_write(va_list ap)
{
	char	*buff;

	buff = va_arg(ap, char *);
	if (!buff)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, buff, ft_strlen(buff));
	return (ft_strlen(buff));
}
