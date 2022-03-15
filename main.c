/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:11:31 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/15 17:31:33 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include <stdio.h>
#include <limits.h>
#define	TESTARG1 '!'
#define	TESTARG2 "bababa cest monstrueux\0 hidden gnagnagna\0"
#define	TESTARG3 2147483647
#define	TESTARG4 (int)-2147483648
#define	TESTARG5 (unsigned int)4294967295
#define	TESTARG6 -42
#define	TESTARG7 -42
#define	TESTARG8 &test1
#define STRING1 "Ceci |%-25c| est un test\n"
#define STRING2 "Ceci |%-25s| est un test\n"
#define STRING3 "Ceci |%+-25i| est un test\n"
#define STRING4 "Ceci |%+-25d| est un test\n"
#define STRING5 "Ceci |%-25u| est un test\n"
#define STRING6 "Ceci |%#-25x| est un test\n"
#define STRING7 "Ceci |%#-25X| est un test\n"
#define STRING8 "Ceci |%25p| est un test\n"
#define STRING9 "Ceci |%5.5%| est un test\n"

int	main(int argc, char **argv)
{
	int	test1;
	int	test2;

	(void)argc;
	(void)argv;
	printf("------------------------------------------------------\n");
	test1 = printf(STRING1, TESTARG1);
	test2 = ft_printf(STRING1, TESTARG1);
	printf("printf: %i\n", test1);
	printf("ft_printf: %i\n", test2);
	printf("------------------------------------------------------\n");
	test1 = printf(STRING2, TESTARG2);
	test2 = ft_printf(STRING2, TESTARG2);
	printf("printf: %i\n", test1);
	printf("ft_printf: %i\n", test2);
	printf("------------------------------------------------------\n");
	test1 = printf(STRING3, TESTARG3);
	test2 = ft_printf(STRING3, TESTARG3);
	printf("printf: %i\n", test1);
	printf("ft_printf: %i\n", test2);
	printf("------------------------------------------------------\n");
	test1 = printf(STRING4, TESTARG4);
	test2 = ft_printf(STRING4, TESTARG4);
	printf("printf: %i\n", test1);
	printf("ft_printf: %i\n", test2);
	printf("------------------------------------------------------\n");
	test1 = printf(STRING5, TESTARG5);
	test2 = ft_printf(STRING5, TESTARG5);
	printf("printf: %i\n", test1);
	printf("ft_printf: %i\n", test2);
	printf("------------------------------------------------------\n");
	test1 = printf(STRING6, TESTARG6);
	test2 = ft_printf(STRING6, TESTARG6);
	printf("printf: %i\n", test1);
	printf("ft_printf: %i\n", test2);
	printf("------------------------------------------------------\n");
	test1 = printf(STRING7, TESTARG7);
	test2 = ft_printf(STRING7, TESTARG7);
	printf("printf: %i\n", test1);
	printf("ft_printf: %i\n", test2);
	printf("------------------------------------------------------\n");
	test1 = printf(STRING8, TESTARG8);
	test2 = ft_printf(STRING8, TESTARG8);
	printf("printf: %i\n", test1);
	printf("ft_printf: %i\n", test2);
	printf("------------------------------------------------------\n");
	test1 = printf(STRING9);
	test2 = ft_printf(STRING9);
	printf("printf: %i\n", test1);
	printf("ft_printf: %i\n", test2);
	return (0);
}
