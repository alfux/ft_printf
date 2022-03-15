/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:11:31 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/15 15:04:54 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include <stdio.h>
#include <limits.h>

int	main(int argc, char **argv)
{
	int	test1;
	int	test2;

	(void)argc;
	(void)argv;
	test1 = 6;
	test2 = 65;
	printf("Ceci |%5.2i| est un test\n", -1);
	ft_printf("Ceci |%5.2i| est un test\n", -1);
	return (0);
}
