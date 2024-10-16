/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:10:04 by eonoh             #+#    #+#             */
/*   Updated: 2024/10/16 22:32:31 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

char	*get_directory_path(t_env_var *env_list, char *path)
{
	char	*homepath;

	homepath = getenv("HOME");
	if (*path == '~')
		path = ft_strjoin(homepath, path);
	// if (*path == '-')
	// {
	// 	if (env_list->oldpwd)
	// }
	return (path);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_const_strcmp(const char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	*ft_strjoin1(char const *s1, char const *s2)
{
	char	*p;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (s1_len + s2_len + 3));
	if (!p)
		return (0);
	ft_strlcpy(p, s1, s1_len + 1);
	ft_strlcpy(p + s1_len, "/", 2);
	ft_strlcpy((p + s1_len + 1), s2, s2_len + 1);
	return (p);
}

// int	is_matched_quote(char *env)
// {
// 	int	single_quote;
// 	int	double_quote;
// 	int	equal_flag;

// 	single_quote = 0;
// 	double_quote = 0;
// 	equal_flag;
	
// 	while (*env)
// 	{

// 		if (*env == '"')
// 			double_quote++;
// 		else if (*env == "'")
// 			single_quote++;
		
// 	}
//	}

// if (*env == '=')
// 		{
// 			perror(*env);
// 			return (NULL);
// 		}

int	get_compare_num(long long digit, long long num)
{
	long long	compare_num;

	compare_num = (num / digit);
	compare_num %= 10;
	return ((int)compare_num);
}

int	compare_two_digits(char *s, int compare_num1, int compare_num2)
{
	if ((*s - '0') == compare_num1)
	{
		if ((*(s + 1) - '0') > compare_num2)
			return (1);
	}
	return (0);
}
