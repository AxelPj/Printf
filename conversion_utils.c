/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:27:19 by axelpeti          #+#    #+#             */
/*   Updated: 2024/11/26 15:31:31 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	compteur;

	compteur = 0;
	if (n == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (n < 0)
	{
		write(1, "-", 1);
		compteur ++;
		n = -n;
	}
	if (n >= 10)
	{
		compteur += ft_putnbr(n / 10);
	}
	compteur += ft_putchar(n % 10 + '0');
	return (compteur);
}

int	ft_unsigned_putnbr(unsigned long n)
{
	int	compteur;

	compteur = 0;
	if (n >= 10)
	{
		compteur += ft_unsigned_putnbr(n / 10);
	}
	ft_putchar(n % 10 + '0');
	compteur ++;
	return (compteur);
}

int	ft_putnbr_base(unsigned long nb)
{
	int		compteur;
	char	*base;

	compteur = 0;
	base = "0123456789abcdef";
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (nb >= 16)
		compteur += ft_putnbr_base(nb / 16);
	ft_putchar(base[nb % 16]);
	compteur++;
	return (compteur);
}

int	ft_putnbr_basemaj(unsigned int nb)
{
	int				compteur;
	char			*base;

	compteur = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		compteur += ft_putnbr_basemaj(nb / 16);
	}
	compteur += ft_putchar(base[nb % 16]);
	return (compteur);
}

int	ft_putptr(void *ptr)
{
	unsigned long	ptr1;

	if (ptr == NULL)
		return (write (1, "(nil)", 5));
	ptr1 = (unsigned long) ptr;
	write(1, "0x", 2);
	return (ft_putnbr_base(ptr1) + 2);
}
