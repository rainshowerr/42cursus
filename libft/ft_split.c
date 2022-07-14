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

static int	ft_get_row(const char *s, char c)
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

static int	ft_size(char const *s, char c, int s_idx)
{
	int	size;

	size = 0;
	while (s[s_idx + size] && s[s_idx + size] != c)
		size++;
	return (size);
}

static char	*ft_malloc(const char *s, int size)
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

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	char	**result;

	if (!s)
		return (0);
	result = (char **)malloc(sizeof(char *) * (ft_get_row(s, c) + 1));
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
			result[k] = ft_malloc(&s[i], ft_size(s, c, i));
			if (!result[k++])
				ft_free(result);
			i += ft_size(s, c, i);
		}
	}
	result[k] = 0;
	return (result);
}
