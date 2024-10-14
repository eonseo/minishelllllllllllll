/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:02:13 by seojang           #+#    #+#             */
/*   Updated: 2024/10/14 18:46:19 by eonoh            ###   ########.fr       */
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
	sort_export(envp, &env_list.export);
	sort_env(envp, &env_list.envs);
	print_export_list(env_list.export);
	printf("\n\n\n");
	print_env_list(env_list.envs);
	while (1)
	{
		line = readline("minishell>");
		if (line)
			ft_tokenizer(line, envp);
		add_history(line);
		free(line);
	}
	return (0);
}