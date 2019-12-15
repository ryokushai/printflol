/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:46:19 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/13 18:46:22 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char  *ft_trim(char *stock, int len_number)
{
	int i;
	char *result;
	int j;

	i = 0;
	j = 0;
	result = malloc(len_number + 1);
	while (stock[i] && i < len_number)
	{
		result[j++] = stock[i++];
	}
	result[j] = '\0';
	return result;
}