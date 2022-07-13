/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:44:57 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/10 20:44:57 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	get_row(const char *s, char c)
{
	int	i;
	int	row;

	i = 0;
	row = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			row++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (row);
}

static char	*w_malloc(const char *s, int size)
{
	int		idx;
	char	*word;

	word = (char *)malloc(size + 1);
	if (!word)
		return (0);
	idx = 0;
	while (idx < size)
	{
		word[idx] = s[idx];
		idx++;
	}
	word[idx] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	int		size;
	char	**result;

	result = (char **)malloc(sizeof(char *) * (get_row(s, c) + 1));
	if (!result)
		return (0);
	k = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			size = 0;
			while (s[i + size] && s[i + size] != c)
				size++;
			result[k++] = w_malloc(&s[i], size);
			i += size;
		}
	}
	result[k] = 0;
	return (result);
}
