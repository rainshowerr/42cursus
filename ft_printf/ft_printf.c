/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:04:04 by seoshin           #+#    #+#             */
/*   Updated: 2022/08/04 20:53:56 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static int	is_cvs(const char	*str)
{
	int	i;

	i = 0;
	if (str[i] == '%' \
	&& (str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == 'p' \
	|| str[i + 1] == 'd' || str[i + 1] == 'i' || str[i + 1] == 'u' \
	|| str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == '%'))
		return (1);
	return (0);
}

static int	ft_write(char c, va_list ap)
{
	if (c == 'c')
		return (ft_c_write(ap));
	else if (c == 's')
		return (ft_s_write(ap));
	else if (c == 'p')
		return (ft_p_write(ap));
	else if (c == 'd' || c == 'i')
		return (ft_di_write(ap));
	else if (c == 'u')
		return (ft_u_write(ap));
	else if (c == 'x' || c == 'X')
		return (ft_xx_write(c, ap));
	else if (c == '%')
	{
		write(1, "%%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	int		j;
	va_list	ap;

	len = 0;
	i = 0;
	j = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (is_cvs(&str[i]))
		{
			len += ft_write(str[i + 1], ap);
			i += 2;
		}
		else
		{
			len += write(1, &str[i], 1);
			i += 1;
		}
	}
	va_end(ap);
	return (len);
}
