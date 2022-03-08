/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:05:02 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/08 16:31:31 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include <stdio.h>
#define TEST_STR "c: %c\ns: %s\np: %p\nd: %d\ni: %i\nu: %u\nx: %x\nX: %X\n%%\n"
#define U_INT_MAX (unsigned int)4294967295

int	main(int argc, char **argv)
{
	int		n;

	if (argc < 2)
		return (1);
	n = -42;
	ft_printf(TEST_STR, **(argv + 1), *(argv + 1), &n, n, n, U_INT_MAX, n, n);
	printf(TEST_STR, **(argv + 1), *(argv + 1), &n, n, n, U_INT_MAX, n, n);
	return (0);
}
