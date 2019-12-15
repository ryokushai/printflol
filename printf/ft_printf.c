/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:45:57 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/13 23:28:59 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_printf;

int		ft_printf(char *format, ...)
{
	va_list	arg;
	int		i;

	char	*str;
	char	*conv;
	int j;
	int num;
	
	char	*stock;
	i = 0;
	va_start(arg, format);
	str = format;
	while (*str != '\0')
	{
		while (*str != '%')
		{
			ft_putchar(*str);
			str++;
			if (*str == '\0')
				break;
		}
		str++;
		conv = ft_conditions(str);	
		num = strlen(conv);
		str = str + num;
		if (*str == 'c')
		{
			j = va_arg(arg, int);
			ft_putchar(j);
		}	
		if (*str == 's')
		{
			stock = va_arg(arg, char *);
			ft_active_string(stock,conv);
		}
		if (*str == 'd')
		{
			stock = ft_itoa(va_arg(arg, int));
			ft_active(stock, conv);
		}
		if (*str == 'x')
		{
			stock = ft_itohexa(va_arg(arg, unsigned long long));
			ft_active(stock, conv);
		}
		if (*str == 'X')
		{
			stock = ft_itohexa2(va_arg(arg, unsigned long long));
			ft_active(stock, conv);
		}
		if (*str == 'p')
		{
			stock = ft_adress(va_arg(arg, unsigned long long));
			ft_active(stock, conv);
		}
		str++;
	}
	printf("ggg %d\n", g_printf);
	return g_printf;
	
	va_end(arg);
}
