/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:36:23 by eonoh             #+#    #+#             */
/*   Updated: 2024/05/07 21:10:09 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <unistd.h>

void	ft_putchar(const char c, int *len);
void	ft_putstr(const char *s, int *len);
void	print_lower_hex(unsigned int ptr, int *len);
void	print_upper_hex(unsigned int ptr, int *len);
void	get_address(void *address, int *len);
void	ft_putnbr(int num, int *len);
void	ft_putunbr(unsigned int num, int *len);
int		print_specifier(const char *content, va_list *ap, int *len);
void	csp_specifier(const char *content, va_list *ap, int *len);
int		ft_printf(const char *content, ...);
void	print_address(unsigned long long ptr, int *len);

#endif