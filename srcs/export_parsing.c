/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:20:23 by eonoh             #+#    #+#             */
/*   Updated: 2024/10/14 00:18:10 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

// quote의 개수가 홀수일경우 dquote모드로 들어감 근데 그거빼고 구현
int	get_equal_sign_idx(char *s)
{
	int				equal_sign_idx;
	unsigned int	i;

	i = 0;
	equal_sign_idx = -1;
	while (s[i])
	{
		if (s[i] == '=')
		{
			equal_sign_idx = i;
			break ;
		}
		i++;
	}
	return (equal_sign_idx);
}

char	*parse_varname(char *s, int equal_sign_idx)
{
	char	*varname;

	if (s[0] == '\0')
		print_error_and_exit(s);
	if (equal_sign_idx == -1)
	{
		varname = ft_strdup(s);
		return (varname);
	}
	if (equal_sign_idx == 0)
		print_error_and_exit("zsh: bad assignment\n");
	varname = ft_substr(s, 0, equal_sign_idx);
	return (varname);
}

char	*parse_value(char *s, int equal_sign_idx)
{
	char	*value;

	if (s[0] == '\0')
		print_error_and_exit(s);
	if (equal_sign_idx == -1)
	{
		value = ft_strdup("");
		return (value);
	}
	if (equal_sign_idx == 0)
		print_error_and_exit("zsh: bad assignment\n");
	value = ft_substr(s, equal_sign_idx + 1, ft_strlen(s));
	return (value);
}
