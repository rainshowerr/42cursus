/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:08:44 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/06 15:50:15 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("%d", isalnum(3));
	printf("%d", isalnum('3'));
	printf("%d", isprint(32));
}
