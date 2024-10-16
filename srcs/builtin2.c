/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:48:34 by eonoh             #+#    #+#             */
/*   Updated: 2024/10/16 23:01:32 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

// list에서 varname 과 같은 걸 찾고, 같으면 지우기.
void	unset(t_tokken_list *option, t_env_var **env_list)
{
	if (!option)
		return ;
	while (option)
	{
		remove_if(&(*env_list)->exports, option->content);
		remove_if(&(*env_list)->envs, option->content);
		option = option->next;
	}
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
