/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:22:03 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/21 19:54:30 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_printf(const char *s, ...);
int	ft_putnbr(int nb);
int	ft_puthex_low(unsigned int n);
int	ft_puthex_upp(unsigned int n);
int	ft_uputnbr(unsigned int n);
int	ft_putptr(unsigned long long p);
int	ft_puthex_ptr(unsigned long long n);

#endif