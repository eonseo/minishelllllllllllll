/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 00:30:13 by eonoh             #+#    #+#             */
/*   Updated: 2024/03/12 01:05:03 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;

	l_len = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (*big != '\0' && (len-- >= l_len))
	{
		if (*big == *little)
		{
			if (ft_strncmp(big, little, l_len) == 0)
				return ((char *)big);
		}
		big++;
	}
	return (NULL);
}
