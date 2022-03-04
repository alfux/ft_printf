/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:05:02 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/04 19:28:25 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	char	**split;
	size_t	i;

	if (argc < 3)
		return (1);
	split = ft_split(*(argv + 1), **(argv + 2));
	i = 0;
	while (*(split + i))
		ft_putendl_fd(*(split + i++), 1);
	return (0);
}
