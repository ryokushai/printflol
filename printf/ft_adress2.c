/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 02:12:55 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/12 02:13:10 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_adress2(unsigned long long n)
{

	char	*str;
	
	str = ft_itohexa2(n);
//	ptr = malloc(100);	
	//ptr = ft_stock("0x",str);
	//ft_putstr(str);
	return str;	
}
