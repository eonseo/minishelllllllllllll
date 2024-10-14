/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:34:50 by eonoh             #+#    #+#             */
/*   Updated: 2024/03/16 16:46:17 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(long long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long long	num;
	int			len;
	char		*p;

	num = (long long)n;
	if (num == 0)
		return (ft_strdup("0"));
	len = num_len(num);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	p[len] = '\0';
	if (num < 0)
	{
		p[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		p[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (p);
}
