/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:45:33 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/10 20:45:33 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	size;

	if (!s)
		return (0);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len < ft_strlen(s) - start)
		size = len;
	else
		size = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, &s[start], size + 1);
	return (str);
}
