/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:37:47 by eonoh             #+#    #+#             */
/*   Updated: 2024/05/08 21:11:39 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(const char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(const char *s, int *len)
{
	while (*s)
	{
		write(1, s++, 1);
		(*len)++;
	}
}
