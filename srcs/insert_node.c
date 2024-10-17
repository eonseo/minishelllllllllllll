/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:24:37 by eonoh             #+#    #+#             */
/*   Updated: 2024/10/18 00:59:58 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

int	if_replace_value(t_env *tmp, char *varname, char *value)
{
	char	*origin_value;

	if (ft_strcmp(tmp->varname, varname) == 0)
	{
		if (value[0] != '\0')
		{
			origin_value = tmp->value;
			tmp->value = ft_strdup(value);
			free(origin_value);
			origin_value = NULL;
		}
		return (1);
	}
	return (0);
}

int	check_same_varname(t_env_var **lst, char *varname, char *value)
{
	t_env	*exports_tmp;
	t_env	*envs_tmp;

	exports_tmp = (*lst)->exports;
	envs_tmp = (*lst)->envs;
	while (exports_tmp && ft_strcmp(exports_tmp->varname, varname) <= 0)
	{
		if (if_replace_value(exports_tmp, varname, value) == 1)
		{
			while (envs_tmp)
			{
				if (if_replace_value(envs_tmp, varname, value) == 1)
					return (1);
				envs_tmp = envs_tmp->next;
			}
		}
		exports_tmp = exports_tmp->next;
	}
	return (0);
}

void	insert_at_head(t_env **lst, t_env *new)
{
	if (*lst)
	{
		new->next = (*lst);
		(*lst)->prev = new;
	}
	*lst = new;
}

void	insert_at_middle(t_env *node, t_env *new)
{
	new->next = node->next;
	new->prev = node;
	node->next->prev = new;
	node->next = new;
}

void	insert_at_end(t_env *node, t_env *new)
{
	if (ft_strcmp(node->varname, new->varname) > 0)
	{
		new->next = node;
		new->prev = node->prev;
		node->prev = new;
		node->prev->next = new;
		return ;
	}
	lst_back(node, new);
}

void	lst_back(t_env *node, t_env *new)
{
	node->next = new;
	new->prev = node;
}

void	insert_in_export_lst(t_env **lst, t_env *new)
{
	t_env	*tmp;

	tmp = *lst;
	if (tmp == NULL || ft_strcmp(tmp->varname, new->varname) > 0)
	{
		insert_at_head(lst, new);
		return ;
	}
	while (tmp->next != NULL)
	{
		if (ft_strcmp(tmp->varname, new->varname) < 0 && \
			ft_strcmp(tmp->next->varname, new->varname) > 0)
		{
			insert_at_middle(tmp, new);
			return ;
		}
		tmp = tmp->next;
	}
	insert_at_end(tmp, new);
}

void	insert_in_env_list(t_env **lst, t_env *new)
{
	t_env	*tmp;

	tmp = *lst;
	if (tmp == NULL)
	{
		insert_at_head(lst, new);
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	lst_back(tmp, new);
}
