/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longlong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:50:40 by eonoh             #+#    #+#             */
/*   Updated: 2024/10/14 00:18:23 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

int	ft_atoll(char *nptr)
{
	int			sign;
	int			i;
	long long	num;

	sign = 1;
	num = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] != '\0')
		exit_error(nptr);
	return (sign * num);
}

int	is_ll_overflow(char *s)
{
	long long	n;
	long long	max;
	int			compare_num1;
	int			compare_num2;

	if (*s == '+')
		s++;
	n = LL_DIGIT;
	max = LL_MAX;
	while (n > 1)
	{
		compare_num1 = get_compare_num(n, max);
		compare_num2 = get_compare_num(n / 10, max);
		if (compare_two_digits(s, compare_num1, compare_num2) == 1)
			return (1);
		s++;
		n /= 10;
	}
	if (*(s + 1) != '\0')
		return (1);
	return (0);
}

int	is_ll_underflow(char *s)
{
	long long	n;
	long long	min;
	int			compare_num1;
	int			compare_num2;

	s++;
	n = LL_DIGIT;
	min = LL_MIN;
	while (n > 1)
	{
		compare_num1 = get_compare_num(n, min) * -1;
		compare_num2 = get_compare_num(n / 10, min) * -1;
		if (compare_two_digits(s, compare_num1, compare_num2) == 1)
				return (1);
		s++;
		n /= 10;
	}
	if (*(s + 1) != '\0')
		return (1);
	return (0);
}

int	is_in_ll_bound(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (*s == '-' || *s == '+')
		i-= 1;
	if (i >= 18)
	{
		if (*s == '-')
		{
			if (is_ll_underflow(s) == 1)
				return (0);
		}
		else
		{
			if (is_ll_overflow(s) == 1)
				return (0);
		}
	}
	return (1);
}
