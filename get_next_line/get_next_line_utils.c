/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:36:58 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/31 18:24:53 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char	*src)
{
	size_t	k;

	if (src == 0)
		return (0);
	k = 0;
	while (src[k] != '\0')
		k++;
	return (k);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == 0)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (0);
	i = -1;
	while (++i < s1_len)
		str[i] = s1[i];
	j = 0;
	while (j < s2_len)
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	s1 = 0;
	return (str);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*str;

	str = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		idx;
	char	cc;
	int		i;

	if (!s)
		return (0);
	cc = (char)c;
	idx = 0;
	i = (int)ft_strlen(s);
	while (idx <= i)
	{
		if (s[idx] == cc)
			return ((char *)&s[idx]);
		idx++;
	}
	return (0);
}
