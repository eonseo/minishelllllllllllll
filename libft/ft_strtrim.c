/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:34:36 by eonoh             #+#    #+#             */
/*   Updated: 2024/03/17 21:18:44 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*p;

	if (!s1)
		return (NULL);
	start = (char *)s1;
	end = (char *)(s1 + ft_strlen(s1) - 1);
	while (ft_strchr(set, *start) != NULL)
		start++;
	while (ft_strchr(set, *end) != NULL)
		end--;
	if (start > end)
		return (ft_strdup(""));
	p = (char *)malloc(sizeof(char) * ((end - start) + 2));
	if (!p)
		return (NULL);
	ft_strlcpy(p, start, (end - start) + 2);
	return (p);
}
