/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmiraill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 02:47:45 by fmiraill          #+#    #+#             */
/*   Updated: 2019/11/18 15:23:54 by fmiraill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(long nbr, char *base)
{
	int				baz;

	baz = ft_strlen(base);
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	if (nbr >= baz)
		ft_putnbr_base(nbr / baz, base);
	write(1, base + (nbr % baz), 1);
}
