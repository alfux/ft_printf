/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrux_lo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:14:01 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/15 17:27:40 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_siznbrh(unsigned int n, size_t ret)
{
	if (!n)
		return (1);
	while (n)
	{
		n /= 16;
		ret++;
	}
	return (ret);
}

static size_t	ft_hyp(t_opt opt, unsigned int n, int fd, size_t ret)
{
	size_t	len;

	len = ft_siznbrh(n, ret);
	if (opt.pou)
		ret += ft_putstr_l("0X", fd);
	if (opt.per && len < opt.pre)
		ret += ft_putnchar_l(opt.pre - len, '0', fd);
	ret = ft_putnbrh_l(1, n, fd, ret);
	if (ret < opt.wid)
		ret += ft_putnchar_l(opt.wid - ret, ' ', fd);
	return (ret);
}

static size_t	ft_zer(t_opt opt, unsigned int n, int fd, size_t ret)
{
	size_t	len;

	len = ft_siznbrh(n, ret);
	if (opt.pou)
		ret += ft_putstr_l("0X", fd);
	if (ret + len < opt.wid)
		ret += ft_putnchar_l(opt.wid - len - ret, '0', fd);
	ret = ft_putnbrh_l(1, n, fd, ret);
	return (ret);
}

static size_t	ft_per(t_opt opt, unsigned int n, int fd, size_t ret)
{
	size_t	len;
	char	pou;

	len = ft_siznbrh(n, ret);
	pou = 2 * opt.pou;
	if (pou + ft_maxof(len, opt.pre) < opt.wid)
		ret += ft_putnchar_l(opt.wid - len - 2 * opt.pou, ' ', fd);
	if (opt.pou)
		ret += ft_putstr_l("0X", fd);
	if (opt.per && len < opt.pre)
		ret += ft_putnchar_l(opt.pre - len, '0', fd);
	ret = ft_putnbrh_l(1, n, fd, ret);
	return (ret);
}

size_t	ft_putnbrX_lo(t_opt opt, unsigned int n, int fd, size_t ret)
{
	if (opt.hyp)
		ret = ft_hyp(opt, n, fd, ret);
	else if (opt.zer && !opt.per)
		ret = ft_zer(opt, n, fd, ret);
	else
		ret = ft_per(opt, n, fd, ret);
	return (ret);
}
