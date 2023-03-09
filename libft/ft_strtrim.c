/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:43:35 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/10 20:43:35 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	is_charset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_start_index(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(s1))
	{
		if (is_charset(s1[i], set))
			i++;
		else
			return (i);
	}
	return (-1);
}

static int	ft_end_index(char const *s1, char const *set)
{
	int	i;

	i = (int)(ft_strlen(s1) - 1);
	while (0 <= i)
	{
		if (is_charset(s1[i], set))
			i--;
		else
			return (i);
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	size;

	size = ft_end_index(s1, set) - ft_start_index(s1, set) + 1;
	if (ft_start_index(s1, set) == -1 && ft_end_index(s1, set) == -1)
		return (ft_strdup("\0"));
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, &s1[ft_start_index(s1, set)], size + 1);
	return (str);
}
