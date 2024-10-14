/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:52:35 by eonoh             #+#    #+#             */
/*   Updated: 2024/03/11 18:28:30 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t count)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	dest = (unsigned char *)dst;
	if (dst > src)
	{
		source = (unsigned char *)(src + count - 1);
		while (count -- > 0)
			dest[count] = *source--;
	}
	else
	{
		source = (unsigned char *)src;
		while (i < count)
			dest[i++] = *source++;
	}
	return ((void *)dest);
}
