/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:52:59 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/08 16:10:35 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"

static void	ft_putnbru_fd(unsigned int nbr, int fd)
{
	if (nbr > 9)
		ft_putnbru_fd(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + 48, fd);
}

static void	ft_putnbrh_fd(char upper, char addr, long long nbr, int fd)
{
	if (nbr > 15)
		ft_putnbrh_fd(upper, addr, nbr / 16, fd);
	else if (addr)
		ft_putstr_fd("0x", fd);
	if (nbr % 16 > 9 && upper)
		ft_putchar_fd(nbr % 16 + 55, fd);
	else if (nbr % 16 > 9)
		ft_putchar_fd(nbr % 16 + 87, fd);
	else
		ft_putchar_fd(nbr % 16 + 48, fd);
}

static void	ft_evaluate(char c, va_list *argl)
{
	if (c == 'c')
		ft_putchar_fd((char)va_arg(*argl, int), 1);
	else if (c == 's')
		ft_putstr_fd((char *)va_arg(*argl, char *), 1);
	else if (c == 'p')
		ft_putnbrh_fd(0, 1, (long long)va_arg(*argl, void *), 1);
	else if (c == 'i' || c == 'd')
		ft_putnbr_fd((int)va_arg(*argl, int), 1);
	else if (c == 'u')
		ft_putnbru_fd((unsigned int)va_arg(*argl, unsigned int), 1);
	else if (c == 'x')
		ft_putnbrh_fd(0, 0, (unsigned int)va_arg(*argl, unsigned int), 1);
	else if (c == 'X')
		ft_putnbrh_fd(1, 0, (unsigned int)va_arg(*argl, unsigned int), 1);
	else if (c == '%')
		ft_putchar_fd(c, 1);
	else
		ft_putstr_fd("{Flag does not exist}", 1);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	argl;

	i = 0;
	va_start(argl, str);
	while (*(str + i))
	{
		if (*(str + i++) == '%')
			ft_evaluate(*(str + i++), &argl);
		else
			ft_putchar_fd(*(str + i - 1), 1);
	}
	va_end(argl);
	return (i);
}
