/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:24:37 by eonoh             #+#    #+#             */
/*   Updated: 2024/10/17 01:38:03 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

int	if_replace_value(t_env_var **lst, t_env *new)
{
	while (*lst && ft_strcmp((*lst)->exports->varname, new->varname) <= 0)
	{
		if (ft_strcmp((*lst)->exports->varname, new->varname) == 0)
		{
			(*lst)->exports->value = ft_strdup(new->value);
			(*lst)->envs->value = ft_strdup(new->value);
			free_node(&new);
			return (1);
		}
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
	node->next = new;
	new->prev = node;
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
