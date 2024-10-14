/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:17:44 by eonoh             #+#    #+#             */
/*   Updated: 2024/10/14 18:44:47 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

void	echo(char **s)
{
	int	newline_flag;

	newline_flag = 1;
	if (ft_strncmp(*s, "-n", 2) == 0)
	{
		newline_flag = 0;
		s++;
	}
	ft_printf("%s", *s);
	if (newline_flag == 1)
		ft_printf("\n");
	exit(EXIT_SUCCESS);
}

void	cd(char **s)
{
	int		result;
	char	*directory_path;

	directory_path = get_directory_path(*s);
	if (directory_path == NULL)
		return ;
	result = chdir((const char *)directory_path);
	if (result == -1)
	{
		perror(directory_path);
		return ;
	}
	exit(EXIT_SUCCESS);
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
	exit(EXIT_SUCCESS);
}

void	sort_env(char **env, t_env **env_list)
{
	t_env	*new;
	int		equal_sign_idx;
	char	*varname;
	char	*value;

	if (!env_list)
		return ;
	while (*env)
	{
		equal_sign_idx = get_equal_sign_idx(*env);
		varname = parse_varname(*env, equal_sign_idx);
		value = parse_value(*env, equal_sign_idx);
		new = make_new_node(varname, value);
		insert_in_env_list(env_list, new);
		free(varname);
		free(value);
		env++;
	}
}

t_env	*export(char *argv, char **envp, t_env_var *env)
{
	t_env	*export;
	t_env	*new;
	char	*varname;
	char	*value;
	int		equal_sign_idx;

	export = NULL;
	new = NULL;
	sort_env(envp, &export);
	if (argv == NULL)
	{
		print_export_list(export);
		return (export);
	}
	equal_sign_idx = get_equal_sign_idx(argv);
	varname = parse_varname(argv, equal_sign_idx);
	value = parse_value(argv, equal_sign_idx);
	new = make_new_node(varname, value);
	insert_in_export_lst(&export, new);
	free(varname);
	free(value);
	return (export);
}
