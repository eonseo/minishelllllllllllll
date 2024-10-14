/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:08:50 by seojang           #+#    #+#             */
/*   Updated: 2024/10/14 01:11:39 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_test.h"

int	ft_lst_len(t_tokken_list *tokken)
{
	int	ret;

	ret = 0;
	while (tokken)
	{
		ret++;
		tokken = tokken->next;
	}
	return (ret);
}

char	*store_path(char **envp)
{
	char	*path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			path = envp[i] + 5;
		i++;
	}
	return (path);
}

void	free_path(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
	paths = NULL;
}

void	ft_val_set(t_tokken_list *tokken, t_val *val)
{
	val->fd_in = -1;
	val->fd_out = -1;
	val->prev_pipe = -1;
	//val->heredoc_fd = -1;
	//val->tokken_len = ft_lst_len(tokken);
}

void	error(char *s, int num)
{
	if (num == 1)
		write(2, s, ft_strlen(s));
	else if (num == 2)
		perror(s);
	else if (num == 3)
	{
		write(2, "command not found: ", ft_strlen("command not found: "));
		write(2, s, ft_strlen(s));
		write(2, "\n", 1);
	}
	exit(EXIT_FAILURE);
}

char *find_path(char *argv, const char *env)
{
	char **paths;
	char *command;
	char *path;
	int i;

	paths = ft_split(env, ':');
	command = ft_strdup(argv);
	i = 0;
	
	if (access(command, F_OK | X_OK) == 0)
	{
		path = ft_strdup(command);
	}
	else
	{
		while (paths[i])
		{
			path = ft_strjoin(paths[i], "/");
			path = ft_strjoin(path, command);
			if (access(path, F_OK | X_OK) == 0)
				break;
			free(path);
			path = NULL;
			i++;
		}
	}
	//free_path(paths);
	//free(command);
	return path;
}

void execute_cmd(t_tokken_list *tokken, char **envp)
{
	char *const env[] = {store_path(envp), NULL};
	char **argv = NULL;
	char *path = NULL;
	int arg_count = 0;

	if (!tokken || !tokken->content || !envp)
		error("Invalid command or environment", 1);
	t_tokken_list *temp = tokken;
	while (temp && temp->content && ft_strncmp(temp->content, "|", 1) != 0 \
	&& ft_strncmp(temp->content, ">", 1) != 0 \
	&& ft_strncmp(temp->content, ">>", 2) != 0 \
	&& ft_strncmp(temp->content, "<", 1) != 0)
	{
		arg_count++;
		temp = temp->next;
	}
	argv = malloc(sizeof(char *) * (arg_count + 1));
	if (!argv)
		error("Memory allocation failed", 2);
	for (int i = 0; i < arg_count; i++)
	{
		argv[i] = ft_strdup(tokken->content);
		tokken = tokken->next;
	}
	argv[arg_count] = NULL;
	path = find_path(argv[0], env[0]);
	if (!path)
		error(argv[0], 3);
	printf("path = %s\n", path);
	while (*argv)
	{
		printf("argv = %s\n", *argv);
		argv++;
	}
	execve(path, argv, envp);
	error("execve failed", 2);
}

void	ft_redir_out(t_tokken_list *tokken, t_val *val) // > 토큰 파이프x 공백x 리다이렉션x    > out
{
	char	*file;

	if (!tokken->next || !tokken->next->content)
		error("redir next cmd error", 1);
	file = ft_strdup(tokken->next->content);
	if ( !file || !ft_strncmp(file, "|", 1))
		error("redir error", 1);
	val->fd_out = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (val->fd_out < 0)
		error("output error", 1);
	tokken->content = ft_strdup("");
	tokken->next->content = ft_strdup("");
}

void	ft_redir_add(t_tokken_list *tokken, t_val *val) //>> out
{
	char	*file;

	if (!tokken->next || !tokken->next->content)
		error("redir next cmd error", 1);
	file = ft_strdup(tokken->next->content);
	if ( !file || !ft_strncmp(file, "|", 1))
		error("redir error", 1);
	val->fd_out = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (val->fd_out < 0)
		error("output error", 1);
	tokken->content = ft_strdup("");
	tokken->next->content = ft_strdup("");
}

void	ft_redir_open(t_tokken_list *tokken, t_val *val)// < infile
{
	char	*file;

	if (!tokken->next || !tokken->next->content)
		error("redir next cmd error", 1);
	file = ft_strdup(tokken->next->content);
	if ( !file || !ft_strncmp(file, "|", 1))
		error("redir error", 1);
	val->fd_in = open(file, O_RDONLY);
	if (val->fd_in < 0)
		error("output error", 1);
	tokken->content = ft_strdup("");
	tokken->next->content = ft_strdup("");
}

void	ft_find_redir(t_tokken_list *tokken, t_val *val)
{
	t_tokken_list	*lst;

	lst = tokken;
	while (lst)
	{
		if (lst->content)
		{
			if (!ft_strncmp(lst->content, ">",1))
				ft_redir_out(lst, val);
			else if (!ft_strncmp(lst->content, ">>",2))
				ft_redir_out(lst, val);
			else if (!ft_strncmp(lst->content, "<",1))
				ft_redir_out(lst, val);
			break ;
		}
		lst = lst->next;
	}
}

void	ft_find_pipe(t_tokken_list *tokken, t_val *val, int *pipefd)
{
	t_tokken_list	*lst;

	lst = tokken;
	while (lst)
	{
		if (lst->content && ft_strncmp(lst->content, "|", 1) == 0)
		{
			val->fd_out = pipefd[1];
			break ;
		}
		lst = lst->next;
	}
}

void	ft_dup(t_val *val, char **envp)
{
	if (!val->cmd)
		exit(EXIT_FAILURE);
	if (val->fd_in != -1)
	{
		if (dup2(val->fd_in, STDIN_FILENO) == -1)
			error("dup2 failed", 2);
		close(val->fd_in);
	}
	if (val->fd_out != -1)
	{
		if (dup2(val->fd_out, STDOUT_FILENO) == -1)
			error("dup2 failed", 2);
		close(val->fd_out);
	}
	//ft_check_bulitin(val->cmd, envp);
	execute_cmd(val->cmd, envp);
	exit(EXIT_FAILURE);
}

void	ft_find_cmd(t_tokken_list *tokken, t_val *val)
{
	t_tokken_list	*lst;

	lst = tokken;
	while (lst && ft_strncmp(lst->content, "|", 1) != 0)
	{
		if (lst->content != NULL || !ft_strlen(lst->content))
		{
			val->cmd = lst;
			break ;
		}
		lst = lst->next;
	}
}

void ft_paser_manager(t_tokken_list *tokken, char **envp)
{
	pid_t pid;
	t_val val;
	int pipefd[2] = {-1, -1};
	t_tokken_list	*lst;

	if (pipe(pipefd) == -1)
		error("pipe failed", 1);
	ft_val_set(tokken, &val);
	//ft_heredoc(tokken); val char *
	while (tokken)
	{
		ft_find_pipe(tokken, &val, pipefd);
		ft_find_redir(tokken, &val);         // cat > out | ls -l      cat NULL NULL | ls -l 
		ft_find_cmd(tokken, &val);
		pid = fork();
		if (pid < 0)
			error("Fork error", 1);
		else if (pid == 0)
			ft_dup(&val, envp); //입 출력 정리 후 exe
		else
		{
			if (val.fd_in != -1)
				close(val.fd_in);
			if (val.fd_out != -1)
				close(val.fd_out);
			val.fd_in = pipefd[0];
			pipefd[0] = -1;
			pipefd[1] = -1;
		}
		while (tokken && tokken->content && ft_strncmp(tokken->content, "|", 1) != 0)
			tokken = tokken->next;
		if (tokken && tokken->content && ft_strncmp(tokken->content, "|", 1) == 0)
			tokken = tokken->next;
	}
	if (val.fd_in != -1)
		close(val.fd_in);
	while (wait(NULL) > 0);
}
