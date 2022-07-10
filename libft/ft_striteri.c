/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:20:43 by marvin            #+#    #+#             */
/*   Updated: 2022/07/10 16:20:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:22:32 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/07 14:39:18 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char	*src)
{
	size_t	k;

	k = 0;
	while (src[k] != '\0')
		k++;
	return (k);
}


void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    int i;

    i = 0;
    while(i < ft_strlen(s))
    {
        f(i, &s[i]);
        i++;
    }
}

void ft_test(unsigned int i, char* c)
{
    if (i % 2 == 1){
        *c = *c + 'a' - 'A';
    }
}

int main(){
    char s[100] = "SEOSHIN";
    ft_striteri(s, ft_test);
    printf("%s", s);
}