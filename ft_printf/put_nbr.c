/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:59:29 by eonoh             #+#    #+#             */
/*   Updated: 2024/05/08 21:11:55 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int num, int *len)
{
	if (num == INT_MIN)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
		(*len)++;
	}
	if (num < 10)
	{
		write(1, &"0123456789"[num], 1);
		(*len)++;
	}
	else
	{
		ft_putnbr(num / 10, len);
		ft_putnbr(num % 10, len);
	}
}

void	ft_putunbr(unsigned int num, int *len)
{
	if (num < 10)
	{
		write(1, &"0123456789"[num], 1);
		(*len)++;
	}
	else
	{
		ft_putnbr(num / 10, len);
		ft_putnbr(num % 10, len);
	}
}
