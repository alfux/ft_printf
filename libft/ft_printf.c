/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:52:59 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/08 18:54:59 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_evaluate(char c, va_list *argl)
{
	size_t	l;

	l = 0;
	if (c == 'c')
		l = ft_putchar_l((char)va_arg(*argl, int), 1);
	else if (c == 's')
		l = ft_putstr_l((char *)va_arg(*argl, char *), 1);
	else if (c == 'p')
		l = ft_putnbrh_l(0, 1, (long long)va_arg(*argl, void *), 1, 0);
	else if (c == 'i' || c == 'd')
		l = ft_putnbr_l((int)va_arg(*argl, int), 1, 0);
	else if (c == 'u')
		l = ft_putnbru_l((unsigned int)va_arg(*argl, unsigned int), 1, 0);
	else if (c == 'x')
		l = ft_putnbrh_l(0, 0, (unsigned int)va_arg(*argl, unsigned int), 1, 0);
	else if (c == 'X')
		l = ft_putnbrh_l(1, 0, (unsigned int)va_arg(*argl, unsigned int), 1, 0);
	else if (c == '%')
		l = ft_putchar_l(c, 1);
	else
		l = ft_putstr_l("{Flag does not exist}", 1);
	return (l);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	len;
	va_list	argl;

	i = 0;
	len = 0;
	va_start(argl, str);
	while (*(str + i))
	{
		if (*(str + i++) == '%')
			len += ft_evaluate(*(str + i++), &argl);
		else
		{
			ft_putchar_fd(*(str + i - 1), 1);
			len++;
		}
	}
	va_end(argl);
	return (len);
}
