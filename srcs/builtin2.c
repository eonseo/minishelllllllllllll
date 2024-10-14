/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:48:34 by eonoh             #+#    #+#             */
/*   Updated: 2024/10/14 02:53:16 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

void	sort_export(char **env, t_env **export)
{
	t_env	*new;
	int		equal_sign_idx;
	char	*varname;
	char	*value;

	if (!export)
		return ;
	while (*env)
	{
		equal_sign_idx = get_equal_sign_idx(*env);
		varname = parse_varname(*env, equal_sign_idx);
		value = parse_value(*env, equal_sign_idx);
		new = make_new_node(varname, value);
		insert_in_export_lst(export, new);
		free(varname);
		free(value);
		env++;
	}
}

// list에서 varname 과 같은 걸 찾고, 같으면 지우기.
t_env	*unset(t_env *export, char *argv)
{
	char	*varname;
	char	*value;
	int		equal_sign_idx;

	if (!argv)
		print_error_and_exit("unset: not enough arguments\n");
	equal_sign_idx = get_equal_sign_idx(argv);
	varname = parse_varname(argv, equal_sign_idx);
	value = parse_value(argv, equal_sign_idx);
	if (value[0] != '\0')
	{
		write(2, value, ft_strlen(value));
		print_error_and_exit(": invalid parameter name\n");
	}
	remove_if(&export, varname);
	free(varname);
	free(value);
	return (export);
	exit(EXIT_SUCCESS);
}
void	do_exit(char *argv)
{
	long long		num;
	unsigned char	exit_status;

	num = ft_atoll(argv);
	if (is_in_ll_bound(argv) == 0)
		exit_error(argv);
	exit_status = (unsigned char)num;
	ft_printf("exit\n");
	exit(exit_status);
}
