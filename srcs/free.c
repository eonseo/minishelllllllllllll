/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:53:05 by eonoh             #+#    #+#             */
/*   Updated: 2024/10/14 22:50:23 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

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
