/*
** mysh.h for includes in /home/dabbec_j/projets/minishell2/includes
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Tue May 21 18:43:04 2013 jalil dabbech
** Last update Mon Jul 01 19:02:27 2013 jalil dabbech
*/

#ifndef MYSH_H_
# define MYSH_H_

typedef struct	s_env
{
  char		*var;
  char		*value;
  struct s_env	*next;
}		t_env;

typedef struct	s_builtins
{
  char		*cmd;
  int		(*fct)(char **, t_env **);
}		t_builtins;

typedef struct	s_cmd
{
  char		*cmd;
  struct s_cmd	*next;
}		t_cmd;

void	*my_malloc(int, char *);
char	**my_wordtabmalloc(int, char *);
void	my_putcharerror(char);
void	my_putstrerror(char *, int);
void	my_putmlkerror(char *);
t_env	*my_put_in_list(t_env *, char *, char *);
char	*my_strndup(char *, int, int);
char	**my_str_to_wordtab(char *);
int	my_strcmp(char *, char *);
void	my_putstr(char *);
void	my_putchar(char);
int	my_strlen(char *);
void	do_sh(t_env **, char **);
char	*where_is_cmd(char *, t_env **);
int	do_cd(char **, t_env **);
int	do_setenv(char **, t_env **);
int	do_unsetenv(char **, t_env **);
int	do_env(char **, t_env **);
int	do_exit(char **, t_env **);
void	my_free_wordtab(char **, int);
int	my_wordtab_size(char **);
void	check_error(char **, char **);
char	**my_cpy_env(t_env **, int);
void	my_free_list(t_env *);
char	**check_cmd(char *, t_env **, char **);
void	stop_the_shell(t_env **, int);
void	set_env_tab(t_env **, int);
void	get_sigint(int);
void	get_eof(int);
char	*my_strdup(char *);
int	is_in_env(char *, char *, t_env **);
char	*my_concat(char *, char *, char);
char    *my_strcat(char *, char *);
char	*my_strncat(char *, char *, int);
void	do_exec(char *, t_env **, char **);
void	my_put_cmd(t_cmd **, char *);

#endif /* !MYSH_H_ */
