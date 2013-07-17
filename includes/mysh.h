/*
** mysh.h for includes in /share/projets/sysunix/msh2/includes
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Tue May 21 18:43:04 2013 jalil dabbech
** Last update mer. juil. 17 06:35:32 2013 jalil dabbech
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

t_env	*my_put_in_list(t_env *, char *, char *);
void	do_sh(t_env **, char **);
char	*where_is_cmd(char *, t_env **);
int	do_cd(char **, t_env **);
int	do_setenv(char **, t_env **);
int	do_unsetenv(char **, t_env **);
int	do_env(char **, t_env **);
int	do_exit(char **, t_env **);
void	check_error(char **, char **);
char	**my_cpy_env(t_env **, int);
void	my_free_list(t_env *);
char	**check_cmd(char *, t_env **, char **);
void	stop_the_shell(t_env **, int);
void	set_env_tab(t_env **, int);
void	get_sigint(int);
void	get_eof(int);
int	is_in_env(char *, char *, t_env **);
char	*my_concat(char *, char *, char);

#endif /* MYSH_H_ */
