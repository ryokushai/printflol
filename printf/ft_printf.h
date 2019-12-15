/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:19:10 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/14 11:53:09 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
#include <stdarg.h>



char	*ft_flags(char *str);
int 	ft_printf(char *format, ...);
void	ft_active_all_1_string(char *conv, char **stock, int len, int i);
void	ft_active_all_string(char	*conv, char **stock,char **number, int i);
int     ft_return_len_printf(int len);
char	*ft_delete_zero(char *conv);
char	*ft_delete_minus(char *stock);
char	*ft_strdup(char *src);
char	*ft_adress(unsigned long long n);
char    *ft_trim(char *stock, int len_number);
void    ft_putstr_write(char *str);
void    ft_active(char *stock, char *conv);
void	ft_active_all(char	*conv, char **stock,char **number, int i);
void    ft_active_string(char *stock, char *conv);
int     ft_isdigit(int c);
char	*ft_width(char *str);
char	*ft_precision(char *str);		
char	*ft_substr(char *s, int start, int len);
void	ft_skip(char *str);
char	*ft_strchr(char *str, int c);
int		ft_strlen(char *str);
int		ft_strlcpy(char *dst, char *src, int n);
void	ft_putchar(char c);
char	*ft_itoa(int n);
char	*ft_itohexa(int n);
char	*ft_itohexa2(int n);
int		ft_lenght(int n);
char	*ft_strrev(char *str);
char	*ft_stock(char *s1, char *s2);
char	*ft_adress(unsigned long long n);
char	*ft_conditions(char *str);
#endif
