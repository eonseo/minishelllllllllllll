/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:53:05 by eonoh             #+#    #+#             */
/*   Updated: 2024/10/14 18:40:54 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

t_env	*make_new_node(char *varname, char *value)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (new == NULL)
		print_error_and_exit("malloc");
	new->varname = ft_strdup(varname);
	new->value = ft_strdup(value);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	free_node(t_env **export)
{
	t_env	*del_node;

	del_node = *export;
	free(del_node->varname);
	free(del_node->value);
	free(del_node);
	del_node = NULL;
}

void	free_list(t_env **export)
{
	t_env	*prev;

	while (*export)
	{
		prev = *export;
		*export = (*export)->next;
		free_node(&prev);
	}
}

void	print_export_list(t_env *export)
{
	t_env	*tmp;

	tmp = export;
	while (tmp != NULL)
	{
		ft_printf("declare -x ");
		ft_printf("%s=\"%s\"\n", tmp->varname, tmp->value);
		tmp = tmp->next;
	}
}

void	print_env_list(t_env *envs)
{
	t_env	*tmp;

	tmp = envs;
	while (tmp != NULL)
	{
		ft_printf("%s=%s\n", tmp->varname, tmp->value);
		tmp = tmp->next;
	}
}
