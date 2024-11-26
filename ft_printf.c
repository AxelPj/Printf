/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:40:28 by axelpeti          #+#    #+#             */
/*   Updated: 2024/11/26 15:33:45 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	int			compteur;
	int			i;

	i = 0;
	va_start(arg, format);
	compteur = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			compteur += ft_parse_printf(format[i], arg);
		}
		else
			compteur += ft_putchar(format[i]);
		i++;
	}
	va_end (arg);
	return (compteur);
}

/* int main ()
{
	#include <stdio.h>
#include "ft_printf.h"

    printf("Testing printf with different formats:\n");
    printf("%%c: %c\n", 'A');
    printf("%%s: %s\n", "Hello, world!");
    printf("%%p: %p\n", (void *)0x12345678);
    printf("%%d: %d\n", 12345);
    printf("%%i: %i\n", -54321);
    printf("%%u: %u\n", 12345);
    printf("%%x: %x\n", 255);
    printf("%%X: %X\n", 255);
    printf("\nTesting ft_printf with different formats:\n");
    ft_printf("%%c: %c\n", 'A');
    ft_printf("%%s: %s\n", "Hello, world!");
    ft_printf("%%p: %p\n", (void *)0x12345678);
    ft_printf("%%d: %d\n", 12345);
    ft_printf("%%i: %i\n", -54321);
    ft_printf("%%u: %u\n", 12345);
    ft_printf("%%x: %x\n", 255);
    ft_printf("%%X: %X\n", 255);
    return (0);
} */
