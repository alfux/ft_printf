/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:11:31 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/15 15:47:16 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include <stdio.h>
#include <limits.h>
#define	TESTARG 1

int	main(int argc, char **argv)
{
	int	test1;
	int	test2;

	(void)argc;
	(void)argv;
	test1 = printf("Ceci |%5.5i| est un test\n", TESTARG);
	test2 = ft_printf("Ceci |%5.5i| est un test\n", TESTARG);
	printf("printf: %i\n", test1);
	printf("ft_printf: %i\n", test2);
	return (0);
}
