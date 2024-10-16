/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:02:13 by seojang           #+#    #+#             */
/*   Updated: 2024/10/16 16:47:17 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_test.h"

// void	handler()
// {
// 	exit(0);
// }
// echo $SHELL$
// 01234567891011
// first_num = 6 - >S
// 11 - 6 = 5
// 10 - 6 + 2 = 
int main(int ac, char **av, char **envp)
{
	char 				*line;
	static t_env_var	env_list;

	line = NULL;
	(void)ac;
	(void)av;
	make_export_list(envp, &env_list.exports);
	make_env_list(envp, &env_list.envs);
	// print_export_list(env_list.exports);
	while (1)
	{
		line = readline("minishell>");
		if (line)
			ft_tokenizer(line, envp, &env_list);
		add_history(line);
		free(line);
	}
	return (0);
}