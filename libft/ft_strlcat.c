/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:11:54 by eonoh             #+#    #+#             */
/*   Updated: 2024/03/12 18:21:49 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (size <= d_len)
	{
		return (s_len + size);
	}
	while (*src && i + 1 + d_len < size)
	{
		dst[i + d_len] = *src++;
		i++;
	}
	dst[i + d_len] = '\0';
	return (d_len + s_len);
}
