/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:37:09 by eonoh             #+#    #+#             */
/*   Updated: 2024/03/16 16:45:11 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	flag;
	int	i;

	count = 0;
	i = 0;
	flag = 1;
	while (s[i])
	{
		if (flag == 1 && s[i] != c)
		{
			count++;
			flag = 0;
		}
		else if (s[i] == c)
		{
			flag = 1;
		}
		i++;
	}
	return (count);
}

static void	ft_free(char **p, int sz)
{
	int	i;

	i = 0;
	while (i < sz)
		free(p[i++]);
	free(p);
}

static char	**split(char const *s, char c, int size, char **p)
{
	char	*start;
	int		i;

	i = 0;
	while (i < size)
	{
		while ((char)*s == c && *s)
			s++;
		start = (char *)s;
		while (*s != c && *s)
			s++;
		p[i] = (char *)malloc(sizeof(char) * ((s - start) + 1));
		if (!p[i])
		{
			ft_free(p, i);
			return (NULL);
		}
		ft_strlcpy(p[i], start, ((s - start) + 1));
		i++;
	}
	p[i] = 0;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char		**p;
	int			size;

	if (!s)
		return (NULL);
	size = count_words(s, c);
	p = (char **)malloc(sizeof(char *) * (size + 1));
	if (!p)
		return (NULL);
	p = split(s, c, size, p);
	return (p);
}
