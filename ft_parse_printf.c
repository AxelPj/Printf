/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:21:37 by axelpeti          #+#    #+#             */
/*   Updated: 2024/11/26 15:22:03 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_printf(char c, va_list arg)
{
	int		compteur;

	compteur = 0;
	if (c == 'c')
		compteur += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		compteur += ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		compteur += ft_putptr(va_arg(arg, void *));
	else if (c == 'd' || c == 'i')
		compteur += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		compteur += ft_unsigned_putnbr(va_arg(arg, unsigned int));
	else if (c == 'x')
		compteur += ft_putnbr_base(va_arg(arg, unsigned int));
	else if (c == 'X')
		compteur += ft_putnbr_basemaj(va_arg(arg, int));
	else if (c == '%')
		return (write (1, "%", 1));
	else
		return (ft_putchar(c));
	return (compteur);
}
