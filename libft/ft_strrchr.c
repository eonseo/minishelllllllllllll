/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:54:07 by eonoh             #+#    #+#             */
/*   Updated: 2024/03/05 03:36:26 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		last_idx;

	ptr = NULL;
	last_idx = ft_strlen(s);
	if (c == 0)
		return ((char *)(s + last_idx));
	while (*s)
	{
		if (*s == c)
		{
			ptr = (char *)s;
		}
		s++;
	}
	return (ptr);
}
