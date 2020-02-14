/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:37:15 by fde-fram          #+#    #+#             */
/*   Updated: 2019/11/24 16:37:17 by fde-fram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	save_nb(int *x, char **str, va_list l)
{
	*x = (**str == '*' && (*str)++) ? va_arg(l, int) : ft_atoi(*str);
	while (ft_isdigit(**str))
		(*str)++;
}

int		ecrit_long(va_list l, t_wpdz wpdz, char *base, char flag)
{
	long	n;
	long	tai;
	int		ret;

	n = (flag == 'd' || flag == 'i') ? va_arg(l, int) : 0;
	if (!(flag == 'd' || flag == 'i'))
		n = (flag == 'p' ? va_arg(l, long) : va_arg(l, unsigned int));
	tai = taille_long(n, ft_strlen(base)) + 2 * (flag == 'p') - (!wpdz.p && !n);
	wpdz.w -= (wpdz.p > tai ? wpdz.p : tai) + (n < 0);
	ret = (wpdz.w > 0 ? wpdz.w : 0) + (wpdz.p > tai ? wpdz.p : tai) + (n < 0);
	(n < 0 && wpdz.z && wpdz.p == -1) ? write(1, "-", 1) : 0;
	if (!(wpdz.d))
		while ((wpdz.w)-- > 0)
			write(1, ((wpdz.z && wpdz.p == -1) ? "0" : " "), 1);
	(n < 0 && !(wpdz.z && wpdz.p == -1)) ? write(1, "-", 1) : 0;
	while ((wpdz.p)-- > (tai))
		write(1, "0", 1);
	(flag == 'p') ? write(1, "0x", 2) : 0;
	if (!(wpdz.p == -1 && n == 0))
		ft_putnbr_base((n < 0 ? -n : n), base);
	if (wpdz.d)
		while ((wpdz.w)-- > 0)
			write(1, " ", 1);
	return (ret);
}

int		ecrit_chaine(va_list l, t_wpdz wpdz, char flag)
{
	char	*s;
	int		n;
	int		ret;

	s = (flag == 's') ? va_arg(l, char*) : (char*)&n;
	!s ? s = "(null)" : 0;
	(flag == '%') ? n = '%' : 0;
	(flag == 'c') ? n = va_arg(l, int) : 0;
	(flag == 's') ? n = ft_strlen(s) : 0;
	wpdz.p = (wpdz.p > n || wpdz.p == -1) ? n : wpdz.p;
	(flag != 's') ? wpdz.p = 1 : 0;
	wpdz.w -= wpdz.p;
	ret = (wpdz.w > 0 ? wpdz.w : 0) + (wpdz.p > 0 ? wpdz.p : 0);
	if (!(wpdz.d))
		while ((wpdz.w)-- > 0)
			write(1, (wpdz.z ? "0" : " "), 1);
	while ((wpdz.p)-- > 0)
		write(1, s++, 1);
	if (wpdz.d)
		while ((wpdz.w)-- > 0)
			write(1, " ", 1);
	return (ret);
}

int		print_flag(char **str, va_list l)
{
	t_wpdz wpdz;

	wpdz = (t_wpdz){.w = 0, .p = -1, .d = 0, .z = 0};
	while (**str == '-' || **str == '0')
	{
		(**str == '-') ? wpdz.d = 1 : 0;
		(**str == '0') ? wpdz.z = 1 : 0;
		(*str)++;
	}
	save_nb(&(wpdz.w), str, l);
	(wpdz.w < 0) ? (wpdz.d = 1) : 0;
	(wpdz.w < 0) ? (wpdz.w = -wpdz.w) : 0;
	if (**str == '.' && (*str)++)
	{
		save_nb(&(wpdz.p), str, l);
		(wpdz.p < 0) ? wpdz.p = -1 : 0;
	}
	if ((**str) == 'd' || (**str) == 'i' || (**str) == 'u')
		return (ecrit_long(l, wpdz, "0123456789", **str));
	else if ((**str) == 'x' || (**str) == 'p' || (**str) == 'X')
		return (ecrit_long(l, wpdz,
			(**str == 'X') ? "0123456789ABCDEF" : "0123456789abcdef", **str));
	else if ((**str) == 'c' || (**str) == 's' || (**str) == '%')
		return (ecrit_chaine(l, wpdz, **str));
	return (-1);
}

int		ft_printf(const char *str, ...)
{
	char	*s;
	va_list	l;
	int		ret;

	ret = 0;
	s = (char *)str;
	va_start(l, str);
	while (*s)
	{
		if (*s == '%' && s++)
			ret += print_flag(&s, l);
		else
		{
			write(1, s, 1);
			ret++;
		}
		s++;
	}
	va_end(l);
	return (ret);
}
