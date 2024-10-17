/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:48:34 by eonoh             #+#    #+#             */
/*   Updated: 2024/10/18 01:43:09 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

// list에서 varname 과 같은 걸 찾고, 같으면 지우기.
void	unset(t_tokken_list *option, t_env_var **lst)
{
	t_env_var	*lst_head;
	t_env		*exports_tmp;
	t_env		*envs_tmp;

	if (!option)
		return ;
	lst_head = *lst;
	while (option)
	{
		init_exports_env_lst(lst_head, &exports_tmp, &envs_tmp);
		remove_if(&exports_tmp, option->content);
		remove_if(&envs_tmp, option->content);
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
