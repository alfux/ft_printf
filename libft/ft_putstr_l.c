/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:46:59 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/09 17:37:09 by afuchs           ###   ########.fr       */
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
	return (ft_putstr_l("(null)", fd));
}

size_t	ft_putstr_lo(t_opt opt, char *s, int fd)
{
	size_t	i;
	size_t	len;

	if (!s)
		return (ft_putstr_lo(opt, "(null)", fd));
	i = 0;
	len = ft_strlen(s);
	if (opt.hyp)
	{
		//FINIR
	}
}
