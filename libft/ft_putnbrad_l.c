/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrad_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:24:44 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/08 20:03:01 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_putnbrad_l(unsigned long long n, int fd, size_t ret)
{
	if (n > 15)
		ret += ft_putnbrad_l(n / 16, fd, ret);
	else
		ret += ft_putstr_l("0x", fd);
	if (n % 16 > 9)
		return (ft_putchar_l(n % 16 + 87, fd) + ret);
	else
		return (ft_putchar_l(n % 16 + 48, fd) + ret);
}
