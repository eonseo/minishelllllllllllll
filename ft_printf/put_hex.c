/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:01:13 by eonoh             #+#    #+#             */
/*   Updated: 2024/05/08 21:11:23 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_lower_hex(unsigned int ptr, int *len)
{
	if (ptr < 16)
	{
		write(1, &"0123456789abcdef"[ptr], 1);
		(*len)++;
	}
	else
	{
		print_lower_hex(ptr / 16, len);
		print_lower_hex(ptr % 16, len);
	}
}

void	print_upper_hex(unsigned int ptr, int *len)
{
	if (ptr < 16)
	{
		write(1, &"0123456789ABCDEF"[ptr], 1);
		(*len)++;
	}
	else
	{
		print_upper_hex(ptr / 16, len);
		print_upper_hex(ptr % 16, len);
	}
}

void	print_address(unsigned long long ptr, int *len)
{
	if (ptr < 16)
	{
		write(1, &"0123456789abcdef"[ptr], 1);
		(*len)++;
	}
	else
	{
		print_address(ptr / 16, len);
		print_address(ptr % 16, len);
	}
}

void	get_address(void *address, int *len)
{
	unsigned long long	ptr;

	ptr = (unsigned long long)address;
	print_address(ptr, len);
}
