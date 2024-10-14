/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 23:44:18 by eonoh             #+#    #+#             */
/*   Updated: 2024/03/07 01:27:46 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*source;
	size_t			i;

	dst = (unsigned char *)dest;
	source = (unsigned char *)src;
	i = 0;
	if (!dst && !source)
		return (NULL);
	while (n-- > 0)
	{
		dst[i++] = *source++;
	}
	return ((void *)dst);
}
