/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:59:41 by eonoh             #+#    #+#             */
/*   Updated: 2024/09/17 20:18:43 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	while (*src)
	{
		if (len + 1 < size)
		{
			*dst++ = *src;
		}
		src++;
		len++;
	}
	if (size > 0)
		*dst = '\0';
	return (len);
}
