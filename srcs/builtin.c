/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:17:44 by eonoh             #+#    #+#             */
/*   Updated: 2024/10/18 01:15:58 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

void	echo(t_tokken_list *option)
{
	int				newline_flag;
	t_tokken_list	*tmp;

	newline_flag = 1;
	tmp = option;
	if (ft_strncmp(tmp->content, "-n", 2) == 0)
	{
		newline_flag = 0;
		tmp = tmp->next;
	}
	ft_printf("%s", tmp->content);
	if (newline_flag == 1)
		ft_printf("\n");
	return ;
}

// list 에 빈문자열 넣었을 때 segfault 뜨는 것 처리하기. parsing 문제인듯 ?? export 까지 안옴
// oldpwd 셋팅: cd 하기 전 oldpwd를 저장. 성공시 env_list->oldpwd = oldpwd. export list 와 envlist 에 넣기.
// unset oldpwd 시 env_list->oldpwd = null, export list와 envlist에서 지우기
// oldpwd 가 setting 되어있으면 dirpath = oldpwd
// oldpwd 가 없으면 perror
void	cd(t_env_var *env_list, t_tokken_list *option)
{
	int		result;
	char	*oldpwd;
	char	*directory_path;

	oldpwd = NULL;
	directory_path = get_directory_path(env_list, option->content);
	if (directory_path == NULL)
		return ;
	oldpwd = getcwd(oldpwd, 0);
	result = chdir((const char *)directory_path);
	if (result == -1)
	{
		perror(directory_path);
		return ;
	}
	if (check_same_varname(&env_list, "OLDPWD", oldpwd) == 0)
	{
		insert_in_export_lst(env_list->exports, make_new_node("OLDPWD", oldpwd));
		insert_in_env_list(env_list->envs, make_new_node("OLDPWD", oldpwd));
	}
	free(oldpwd);
	oldpwd = NULL;
	return ;
}

void	pwd(void)
{
	char	*cwd;

	cwd = NULL;
	cwd = getcwd(cwd, 0);
	if (cwd == NULL)
	{
		perror(cwd);
		return ;
	}
	ft_printf("%s", cwd);
	ft_printf("\n");
	free(cwd);
	return ;
}

void	export(t_tokken_list *option, t_env_var **env_list)
{
	t_env		*new;
	char		*varname;
	char		*value;

	new = NULL;
	if (!option)
	{
		print_export_list((*env_list)->exports);
		return ;
	}
	varname = option->content;
	if (option->next)
		value = option->next->content;
	else
		value = ft_strdup("");
	if (check_same_varname(env_list, varname, value) == 1)
		return ;
	insert_in_export_lst(&(*env_list)->exports, make_new_node(varname, value));
	insert_in_env_list(&(*env_list)->envs, make_new_node(varname, value));
	free(varname);
	free(value);
	return ;
}
