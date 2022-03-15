/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:52:59 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/15 15:06:16 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	ft_isopt(char c)
{
	if (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

static t_opt	ft_init_opt(void )
{
	t_opt	opt;

	opt.hyphen = 0;
	opt.zero = 0;
	opt.period = 0;
	opt.pound = 0;
	opt.space = 0;
	opt.plus = 0;
	opt.width = 0;
	opt.precision = 0;
	return (opt);
}

static size_t	ft_get_opt(char *str, size_t *i)
{
	t_opt	options;

	options = ft_init_opt();
	while (ft_isopt(str + *i))
	{
		if (str + *i == '-')
			options.hyp = 1;
		else if (str + *i == '0')
			options.zer = 1;
		else if (str + *i == '#')
			options.pou = 1;
		else if (str + *i == ' ')
			options.spa = 1;
		else
			options.plu = 1;
		(*i)++;
	}
	options.wid = ft_atoi(str + *i);
	while (ft_isdigit(str + *i))
		(*i)++;
	if (str + *i == '.')
		options.pre = ft_atoi(str + ++(*i));
	while (ft_isdigit(str + *i))
		(*i)++;
	return (options);
}

static size_t	ft_evaluate(char *str, size_t *i, va_list *argl)
{
	size_t	l;
	t_opt	opt;

	l = 0;
	opt = ft_get_opt(str, i);
	if (*(str + *i) == 'c')
		l = ft_putchar_lo(opt, (char)va_arg(*argl, int), 1);
	else if (*(str + *i) == 's')
		l = ft_putstr_lo(opt, (char *)va_arg(*argl, char *), 1);
	else if (*(str + *i) == 'p')
		l = ft_putnbrad_lo(opt, (long long)va_arg(*argl, void *), 1, 0);
	else if (*(str + *i) == 'i' || *(str + *i) == 'd')
		l = ft_putnbr_lo(opt, (int)va_arg(*argl, int), 1, 0);
	else if (*(str + *i) == 'u')
		l = ft_putnbru_lo(opt, (unsigned int)va_arg(*argl, unsigned int), 1, 0);
	else if (*(str + *i) == 'x')
		l = ft_putnbrx_lo(opt, (unsigned int)va_arg(*argl, unsigned int), 1, 0);
	else if (*(str + *i) == 'X')
		l = ft_putnbrX_lo(opt, (unsigned int)va_arg(*argl, unsigned int), 1, 0);
	else if (*(str + *i) == '%')
		l = ft_putchar_lo(opt, *(str + *i), 1);
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
			len += ft_evaluate(str, &i, &argl);
		else
		{
			ft_putchar_fd(*(str + i - 1), 1);
			len++;
		}
	}
	va_end(argl);
	return (len);
}
