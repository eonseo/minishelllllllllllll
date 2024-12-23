/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:54:44 by eonoh             #+#    #+#             */
/*   Updated: 2024/10/18 01:02:55 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

void	print_export_list(t_env *export)
{
	t_env	*tmp;

	tmp = export;
	while (tmp != NULL)
	{
		if (tmp->varname[0] != '_')
		{
			ft_printf("declare -x ");
			ft_printf("%s=\"%s\"\n", tmp->varname, tmp->value);
		}
		tmp = tmp->next;
	}
}

void	print_env_list(t_env *envs)
{
	t_env	*tmp;

	tmp = envs;
	while (tmp != NULL)
	{
		if (tmp->value[0] != '\0')
			ft_printf("%s=%s\n", tmp->varname, tmp->value);
		tmp = tmp->next;
	}
}
