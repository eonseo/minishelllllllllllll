/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:22:27 by eonoh             #+#    #+#             */
/*   Updated: 2024/10/14 00:18:26 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

void	remove_head(t_env **lst)
{
	t_env	*del_node;

	del_node = *lst;
	*lst = (*lst)->next;
	(*lst)->prev = NULL;
	free_node(&del_node);
}

void	remove_node(t_env *node)
{
	t_env	*del_node;

	del_node = node;
	del_node->prev->next = del_node->next;
	del_node->next->prev = del_node->prev;
	free_node(&del_node);
}

void	remove_tail(t_env *node)
{
	t_env	*del_node;

	del_node = node;
	del_node->prev->next = NULL;
	free_node(&del_node);
}

void	remove_if(t_env **export, char *varname)
{
	t_env	*tmp;

	tmp = *export;
	if (ft_strcmp(tmp->varname, varname) == 0)
	{
		remove_head(export);
		return ;
	}
	while (tmp->next)
	{
		if (ft_strcmp(tmp->varname, varname) == 0)
		{
			remove_node(tmp);
			return ;
		}
		tmp = tmp->next;
	}
	if (ft_strcmp(tmp->varname, varname) == 0)
		remove_tail(tmp);
}
