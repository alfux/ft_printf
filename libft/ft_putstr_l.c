/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:46:59 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/15 14:56:48 by afuchs           ###   ########.fr       */
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
	if (opt.per)
		len = opt.pre;
	else
		len = ft_strlen(s);
	if (opt.hyp)
	{
		while (*(s + i) && i < len)
			ft_putchar_fd(*(s + i++), fd);
		while (i++ < opt.wid)
			ft_putchar_fd(' ', fd);
	}
	else
	{
		while (i++ + len < opt.wid)
			ft_putchar_fd(' ', fd);
		while (*(s + i - 1) && i - 1 < len)
			ft_putchar_fd(*(s + i++), fd);
	}
	return (i - 1);
}
