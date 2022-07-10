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

#include "includes/libft.h"

size_t	ft_strlen(const char	*src)
{
	size_t	k;

	k = 0;
	while (src[k] != '\0')
		k++;
	return (k);
}

int is_charset(char c, char const *set)
{
    size_t i;

    i = 0;
    while(i < ft_strlen(set))
    {
        if (c == set[i])
            return 1;
        i++;
    }
    return 0;
}

int ft_start_index(char const *s1, char const *set)
{
    int i;

    i = 0;
    while(i < (int)ft_strlen(s1))
    {
        if (is_charset(s1[i], set))
            i++;
        else
            return (i);
    }
    return (-1);
}

int ft_end_index(char const *s1, char const *set)
{
    int i;

    i = (int)(ft_strlen(s1) - 1);
    while(0 <= i)
    {
        if (is_charset(s1[i], set))
            i--;
        else
            return (i);
    }
    return (-1);
}

char *ft_strtrim(char const *s1, char const *set)
{
    char    *str;
    size_t  size;
    size_t i;
    int j;

    if (ft_end_index(s1, set) == -1 && ft_end_index(s1, set) == -1)
        return (0);
    size = ft_end_index(s1, set) - ft_start_index(s1, set) + 1;
    str = malloc(sizeof(char) * (size + 1));
    if (!str)
        return (0);
    i = 0;
    j = ft_start_index(s1, set);
    while(i < size)
    {
        str[i] = s1[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return (str);
}
