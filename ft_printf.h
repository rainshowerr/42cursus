/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:03:05 by seoshin           #+#    #+#             */
/*   Updated: 2022/08/04 20:42:49 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

size_t	ft_strlen(const char	*src);
int		ft_putnbr(long long n);
int		ft_hexadec(unsigned long long nbr, char *base);
int		ft_c_write(va_list ap);
int		ft_s_write(va_list ap);
int		ft_p_write(va_list ap);
int		ft_di_write(va_list ap);
int		ft_u_write(va_list ap);
int		ft_xx_write(int c, va_list ap);
int		ft_printf(const char *str, ...);

#endif