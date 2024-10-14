#ifndef MS_TEST_H
# define MS_TEST_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

# define LL_MAX	9223372036854775807LL
# define LL_MIN -9223372036854775807LL - 1
# define LL_DIGIT 1000000000000000000

typedef enum	e_builtin_code
{
	CD = 1,
	ECHO,
	ENV,
	EXIT,
	EXPORT,
	PWD,
	UNSET,
}	t_builtin_code;


typedef struct s_env
{
	char			*varname;
	char			*value;
	struct s_env	*prev;
	struct s_env	*next;
}	t_env;

typedef struct	s_env_var
{
	t_env	*envs;
	t_env	*export;
}	t_env_var;

typedef struct s_flag
{
	int	pipe;
}	t_flag;

typedef struct s_tokken_list
{
	char			*content;
	struct s_tokken_list	*next;
}					t_tokken_list;

//typedef struct s_list
//{
//	void			*content;
//	struct s_list	*next;
//}					t_list;

typedef struct s_val
{
	int	prev_pipe;
	int	fd_in;
	int	fd_out;
	int	heredoc_fd;
	int	tokken_len;
	int	redir_flag;
	t_tokken_list	*cmd;
}			t_val;

typedef struct s_word
{
	int			count;
	int			flag;
	int			single_quote_flag;
	int			double_quote_flag;
	int			quote_flag;
	const char	*start;
	const char	*end;
}			t_word;

//libft.c
int		ft_is_digit(char c);
int		ft_is_alpha(char c);

//lst_util.c
t_tokken_list	*ft_lstnew(char *content);
void	ft_lstadd_back(t_tokken_list **lst, t_tokken_list *new);
void	ft_lstclear(t_tokken_list **lst);

//token
void	ft_tokenizer(char *line, char **envp);
void	ft_in_pipe(char *line, char **envp, t_tokken_list **tokken);
char	*ft_alpha_digit(char *line, int *i);
char	*ft_double_qoute_check(char *line, int *i, char **envp);
char	*ft_export_ptr(char *line, int *i, char **envp);
char	*ft_export_push(char *temp, char **envp);
char	*ft_single_qoute_check(char *line, int *i);
char	*ft_redirection_check(char *line, int *i);
char	*ft_option(char	*line, int *i);

// ft_utils
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(char const *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// ft_split.c
char	**split(const char *s, char c, int size, char **p);
char	**ft_split(const char *s, char c);
void	flag1_case(t_word *word, char s, char c);
int		count_words(const char *s, char c);
void	end_of_word(const char **s, char c, t_word *word);

//ft_split_utils.c
void	ft_free(char **p, int sz);
void	init_word(t_word *word);
int		is_quote(const char *s);

//ft_qoute.c
int		ft_double_qoute(char *line, int i, char **envp);
int		ft_single_qoute(char *line, int i);
void	ft_qoute_check(char *line, char **envp, t_flag *flag);

//ft_export.c
void	ft_print_export(char *temp, char **envp);
int		ft_export_check(char *line, int i, char **envp);

//ft_paser
int		ft_lst_len(t_tokken_list *tokken);
char	*store_path(char **envp);
char	*find_path(char *argv, const char *env);
void	ft_val_set(t_tokken_list *tokken, t_val *val);
void	error(char *s, int num);
void	execute_cmd(t_tokken_list *tokken, char **envp);
void	ft_redir(t_tokken_list *tokken, t_val *val);
void	ft_paser_manager(t_tokken_list *tokken, char **envp);
void	free_path(char **paths);

//redir
void	ft_redir_open(t_tokken_list *tokken, t_val *val);
void	ft_redir_out(t_tokken_list *tokken, t_val *val);
void	ft_redir_add(t_tokken_list *tokken, t_val *val);

void	ft_find_cmd(t_tokken_list *tokken, t_val *val);
void	ft_dup(t_val *val, char **envp);
void	ft_find_pipe(t_tokken_list *tokken, t_val *val, int *pipefd);
void	ft_find_redir(t_tokken_list *tokken, t_val *val);

// builtin.c
void	cd(char **s);
void	echo(char **s);
void	pwd(void);
t_env	*export(char *argv, char **envp, t_env_var *env);
void	sort_env(char **env, t_env **envs);

// utils.c
char	*get_directory_path(char *path);
int		ft_strcmp(char *s1, char *s2);
int		get_compare_num(long long digit, long long num);
int		compare_two_digits(char *s, int compare_num1, int compare_num2);

// export_parsing.c
int		get_equal_sign_idx(char *s);
char	*parse_varname(char *s, int equal_sign_idx);
char	*parse_value(char *s, int equal_sign_idx);

// builtin2.c
void	sort_export(char **env, t_env **export);
t_env	*unset(t_env *export, char *argv);
void	do_exit(char *argv);

// error.c
void	print_error_and_exit(char *s);
void	exit_error(char *s);

// remove.c
void	remove_head(t_env **lst);
void	remove_node(t_env *node);
void	remove_tail(t_env *node);
void	remove_if(t_env **export, char *varname);

// insert.c
void	insert_at_head(t_env **lst, t_env *new);
void	insert_at_middle(t_env *node, t_env *new);
void	insert_at_end(t_env *node, t_env *new);
void	lst_back(t_env *node, t_env *new);
void	insert_in_export_lst(t_env **lst, t_env *new);
void	insert_in_env_list(t_env **lst, t_env *new);

// list_utils.c
t_env	*make_new_node(char *varname, char *value);
void	free_node(t_env **export);
void	free_list(t_env **export);
void	print_export_list(t_env *export);
char	*ft_strjoin1(char const *s1, char const *s2);
void	print_env_list(t_env *envs);

// longlong.c
int		ft_atoll(char *nptr);
int		is_ll_overflow(char *s);
int		is_ll_underflow(char *s);
int		is_in_ll_bound(char *s);

// execute_builtin.c
t_builtin_code	is_builtin(t_val *val);
void			ft_check_bulitin(t_tokken_list *lst, char **envp, char *av);

#endif /* MS_TEST_H*/