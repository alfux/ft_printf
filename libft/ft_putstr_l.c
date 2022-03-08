/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:46:59 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/08 17:50:09 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_putstr_l(char *s, int fd)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (*(s + i))
			ft_putchar_fd(*(s + i++), fd);
		return (i);
	}
	return (0);
}
