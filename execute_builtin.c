/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 00:29:03 by eonoh             #+#    #+#             */
/*   Updated: 2024/10/14 03:08:00 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_test.h"

t_builtin_code	is_builtin(t_val *val)
{
	const char		*builtins = {"cd", "echo", "env", "exit", "export", \
							"pwd", "unset", NULL};
	int				i;
	t_builtin_code	builtin_code;
	
	i = 0;
	while (builtins[i])
	{
		if (strcmp(builtins[i], val->cmd) == 0)
		{
			builtin_code = i + 1;
			return (i);
		}
		i++;
	}
	return (0);
}

void	ft_check_bulitin(t_tokken_list *lst, char **envp, char *av, t_env_var *env_list)
{
 	t_builtin_code	builtin_code;
	static t_env	*my_export;

	builtin_code = is_builtin(av);
	if (builtin_code == 0)
		return ;
 	if (builtin_code == CD)
		cd(lst->next->content);
	else if (builtin_code == ECHO)
		echo(lst->next->content);
	else if (builtin_code == ENV)
		print_env_list(envp);
	else if (builtin_code == EXIT)
		do_exit(lst->next->content);
	else if (builtin_code == export)
		export(lst->next->content, envp);
	else if (builtin_code == PWD)
		pwd();
	else
		unset()
}
