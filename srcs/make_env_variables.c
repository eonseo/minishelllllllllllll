/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_env_variables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:51:19 by eonoh             #+#    #+#             */
/*   Updated: 2024/10/16 23:15:17 by eonoh            ###   ########.fr       */
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

// value null 처리
void	make_export_list(char **envp, t_env **export)
{
	t_env	*new;
	int		equal_sign_idx;
	char	*varname;
	char	*value;

	if (!export)
		return ;
	while (*envp)
	{
		equal_sign_idx = get_equal_sign_idx(*envp);
		varname = parse_varname(*envp, equal_sign_idx);
		value = parse_value(*envp, equal_sign_idx);
		new = make_new_node(varname, value);
		insert_in_export_lst(export, new);
		free(varname);
		free(value);
		envp++;
	}
}

void	make_env_list(char **envp, t_env **env_list)
{
	t_env	*new;
	int		equal_sign_idx;
	char	*varname;
	char	*value;

	if (!env_list)
		return ;
	while (*envp)
	{
		equal_sign_idx = get_equal_sign_idx(*envp);
		varname = parse_varname(*envp, equal_sign_idx);
		value = parse_value(*envp, equal_sign_idx);
		new = make_new_node(varname, value);
		insert_in_env_list(env_list, new);
		free(varname);
		free(value);
		envp++;
	}
}
