/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 01:36:41 by eonoh             #+#    #+#             */
/*   Updated: 2024/10/18 01:41:54 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

void	init_exports_env_lst(t_env_var *lst_head, t_env **exports, t_env **envs)
{
	*exports = lst_head->exports;
	*envs = lst_head->envs;
}