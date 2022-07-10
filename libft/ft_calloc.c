/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:41:20 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/10 20:41:20 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    void *space;
    if (!(space = malloc(nmemb * sizeof(size))))
        return (0);
    return (space);
}