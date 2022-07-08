/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:49:59 by marvin            #+#    #+#             */
/*   Updated: 2022/07/08 16:49:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
    int i;
    int j;

    i = 0;
    j = 0;
    while(j < ft_strlen(set))
    {
        if (c == set[j])
            return 1;
        j++;
    }
    return 0;
}

int ft_start_index(char const *s1, char const *set)
{
    int i;
    int flag;

    i = 0;
    while(i < ft_strlen(s1))
    {
        if (is_charset(s1[i], set))
            i++;
        else
            return i;
    }
}

int ft_end_index(char const *s1, char const *set)
{
    int i;
    int flag;

    i = ft_strlen(s1) - 1;
    while(0 <= i)
    {
        if (is_charset(s1[i], set))
            i--;
        else
            return i;
    }
}

char *ft_strtrim(char const *s1, char const *set)
{
    char    *str;
    size_t  size;
    int i;
    int j;

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

int main(){
    printf("%s", ft_strtrim("!(*!@seo&*!shin!@#(", "#@*!("));
}