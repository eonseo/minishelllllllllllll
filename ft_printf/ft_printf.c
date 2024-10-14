/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:23:07 by eonoh             #+#    #+#             */
/*   Updated: 2024/05/08 21:11:29 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	csp_specifier(const char *content, va_list *ap, int *len)
{
	void	*ptr;

	ptr = NULL;
	if (*(content + 1) == 'c')
		ft_putchar((char)va_arg(*ap, int), len);
	else if (*(content + 1) == 's')
	{
		ptr = va_arg(*ap, char *);
		if (ptr == NULL)
			ft_putstr("(null)", len);
		else
			ft_putstr(ptr, len);
	}
	else if (*(content + 1) == 'p')
	{
		ptr = va_arg(*ap, void *);
		if (ptr == NULL)
			ft_putstr("(nil)", len);
		else
		{
			write(1, "0x", 2);
			*len += 2;
			get_address(ptr, len);
		}
	}
}

int	print_specifier(const char *content, va_list *ap, int *len)
{
	int	return_value;

	return_value = 0;
	if (*(content + 1) == 'd' || *(content + 1) == 'i')
		ft_putnbr(va_arg(*ap, int), len);
	else if (*(content + 1) == 'u')
		ft_putunbr(va_arg(*ap, unsigned int), len);
	else if (*(content + 1) == 'x')
		print_lower_hex(va_arg(*ap, int), len);
	else if (*(content + 1) == 'X')
		print_upper_hex(va_arg(*ap, int), len);
	else if (*(content + 1) == '%')
		ft_putchar('%', len);
	else if (*(content + 1) == 'c' || *(content + 1) == 's' || \
			*(content + 1) == 'p')
		csp_specifier(content, ap, len);
	else
		return (1);
	return (return_value);
}

int	ft_printf(const char *content, ...)
{
	int		len;
	va_list	ap;

	if (!content)
		return (-1);
	len = 0;
	va_start(ap, content);
	while (*content)
	{
		if (*content == '%')
		{
			if (print_specifier(content, &ap, &len))
				return (-1);
			else
				content += 2;
		}
		else
		{
			write(1, (const void *)content, 1);
			content++;
			len++;
		}
	}
	va_end(ap);
	return (len);
}
