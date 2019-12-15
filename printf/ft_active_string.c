/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:55:34 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/12 14:55:36 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char 	*add;
int 	len_number;
int		len_stock;

void	ft_active_all_1_string(char *conv, char **stock, int len, int i)
{
	if (conv[i] == '0')
	{
		memset(add, '0', len);
		*stock= ft_stock(add, *stock);
	}
	
	else if (ft_isdigit(conv[i]))
	{
		memset(add, ' ', len);
		*stock = ft_stock(add, *stock);
	
	}
	if (conv[i] == '-')
	{
		memset(add, ' ', len);
		*stock = ft_stock(*stock, add);
	
	}
	if (conv[i] == '.')
	{
		if (len_stock - len_number <= 0)
			{
				*stock = ft_strdup(*stock);
			}
		else if (len_stock - len_number > 0)
		{
			*stock = ft_trim(*stock, len_number);
		}
	}
}

void	ft_active_all_string(char	*conv, char **stock,char **number, int i)
{
	int		len;

	//char    *add;
	if (atoi(*number) == 0 && atoi(*stock) == 0)
	{
		*stock = "";
		free(*number);
		*number = NULL;
		return ;
	}
	len = atoi(*number) - ft_strlen(*stock);
    len_number = atoi(*number);
	len_stock = ft_strlen(*stock);
	free(*number);
	*number = NULL;
	
	/*
	if (len <= 0 )
		return ;
	*/	
	add = malloc(len + 1);
	ft_active_all_1_string(conv, stock, len, i);
	
}

void	ft_active_string(char *stock, char *conv)
{
	int		i;
	char 	*number;
	int		count;

	
	i = ft_strlen(conv);
	number = NULL;
	count = 0;
	i--;
	if (strchr(conv, '.') && conv[0] == '0')
		conv = ft_delete_zero(conv);
	while (i >= 0)
	{
		if (ft_isdigit(conv[i]))
		{
			if (number == NULL)
			{
				number = malloc(strlen(conv) + 1);
			}
			number[count] = conv[i];	
			count++;
			if (i == 0 && conv[i] != '0')
			{
				count = 0;	
				number = ft_strrev(number);
				ft_active_all_string(conv, &stock, &number, i);	
				conv[count] = '\0';
			}
		}
		if (conv[i] == '-' && number)
		{
			count = 0;
			number = ft_strrev(number);
			ft_active_all_string(conv, &stock, &number, i);
		}
		if (conv[i] == '.')
		{
			len_number = atoi(number);
			len_stock = ft_strlen(stock);
			if (len_stock - len_number <= 0)
			{
				count = 0;
				number = ft_strrev(number);
				ft_active_all_string(conv,&stock, &number, i);
			}
			else if (len_stock - len_number > 0)
			{
				count = 0;
				number = ft_strrev(number);
				ft_active_all_string(conv, &stock, &number, i);
			}	
		}
		if (conv[i] == '0' && number && i == 0)
		{
			count = 0;
			number = ft_strrev(number);
			ft_active_all_string(conv, &stock, &number, i);
		}	
		i--;
	}
	ft_putstr_write(stock);
}
