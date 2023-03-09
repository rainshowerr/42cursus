/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:36:58 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/21 00:34:32 by seoshin          ###   ########.fr       */
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
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;

	if (s1 == 0)
		return (ft_strdup(s2));
	s1_len = (int)ft_strlen(s1);
	s2_len = (int)ft_strlen(s2);
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
	size_t	i;
	size_t	len;
	char	cc;

	if (!s)
		return (0);
	cc = (char)c;
	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
