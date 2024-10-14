/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:02:53 by eonoh             #+#    #+#             */
/*   Updated: 2024/03/05 03:32:44 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	last_idx;

	last_idx = ft_strlen(s);
	if (c == 0)
		return ((char *)(s + last_idx));
	while (*s)
	{
		if (*s == (unsigned char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}
