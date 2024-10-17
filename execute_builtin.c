/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 00:29:03 by eonoh             #+#    #+#             */
/*   Updated: 2024/10/17 22:32:37 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_test.h"

t_code	is_builtin(t_tokken_list *lst)
{
	const char		*builtins[] = {"cd", "echo", "env", "exit", "export", \
								"pwd", "unset", NULL};
	char			*command;
	int				i;
	t_code			builtin_code;

	i = 0;
	command = lst->content;
	while (builtins[i])
	{
		if (ft_const_strcmp(builtins[i], command) == 0)
		{
			builtin_code = i + 1;
			return (builtin_code);
		}
		i++;
	}
	return (0);
}

int	ft_check_bulitin(t_tokken_list *lst, t_env_var **env_list)
{
 	t_code			builtin_code;
	t_tokken_list	*option;

	builtin_code = is_builtin(lst);
	if (builtin_code == 0)
		return (0);
	option = lst->next;
 	if (builtin_code == CD)
		cd(*env_list, option);
	else if (builtin_code == ECHO)
		echo(option);
	else if (builtin_code == ENV)
		print_env_list((*env_list)->envs);
	else if (builtin_code == EXIT)
		do_exit(lst->next->content);
	else if (builtin_code == EXPORT)
		export(option, env_list);
	else if (builtin_code == PWD)
		pwd();
	else
		unset(option, env_list);
	return (1);
}
