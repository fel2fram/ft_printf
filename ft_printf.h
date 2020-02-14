/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:56:51 by fde-fram          #+#    #+#             */
/*   Updated: 2019/11/24 16:40:58 by fde-fram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_wpdz
{
	int w;
	int p;
	int d;
	int z;
}				t_wpdz;
int				ft_atoi(const char *str);
int				taille_long(long n, int base);
int				ft_isdigit(int i);
int				ft_strlen(const char *str);
void			ft_putnbr_base(long nbr, char *base);
void			save_nb(int *x, char **str, va_list l);
int				ecrit_long(va_list l, t_wpdz wpdz, char *base, char flag);
int				ecrit_chaine(va_list l, t_wpdz wpdz, char flag);
int				print_flag(char **str, va_list l);
int				ft_printf(const char *str, ...);

#endif
