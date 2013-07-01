/*
** exec.c for sources in /home/dabbec_j/projets/minishell2/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Thu Jun 27 19:18:55 2013 jalil dabbech
** Last update Mon Jul 01 19:02:24 2013 jalil dabbech
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"
#include "get_next_line.h"

char	**assign_args(char **cmd_tab)
{
  int	i;
  char	**ret;

  i = 0;
  while (cmd_tab[i])
    i++;
  ret = my_wordtabmalloc(i, "assign_args. \n");
  i = 0;
  while (cmd_tab[i])
  {
    ret[i] = my_strdup(cmd_tab[i]);
    i++;
  }
  ret[i] = NULL;
  return (ret);
}

void	exec_cmd(char **cmd_tab, t_env **my_env, char **env_tab)
{
  char	**arg;

  arg = assign_args(cmd_tab);
  if (execve(cmd_tab[0], arg, env_tab) == -1)
  {
    if (!(cmd_tab[0] = where_is_cmd(cmd_tab[0], my_env)))
      exit(EXIT_FAILURE);
    arg = assign_args(cmd_tab);
    if ((execve(cmd_tab[0], arg, env_tab)) == -1)
      check_error(cmd_tab, arg);
  }
  my_free_wordtab(arg, my_wordtab_size(arg));
  my_free_wordtab(cmd_tab, my_wordtab_size(cmd_tab));
  exit(EXIT_SUCCESS);
}

int	check_multiple_cmd(char *cmd, t_cmd **my_cmd)
{
  int	i;

  i = 0;
  while (cmd[i])
  {
    if (cmd[i] == ';' || cmd[i] == '|')
    {
      if (i == 0 && cmd[i] == '|')
      {
	write(2, "mysh: parse error near '|'\n", 27);
	return (0);
      }
      my_put_cmd(my_cmd, my_strndup(cmd, 0, i));
    }
    i++;
  }
  return (1);
}

int	check_redirection(char *cmd)
{
  int	i;
  int	ret;

  i = 0;
  ret = 0;
  while (cmd[i])
  {
    if (cmd[i] == '<' || cmd[i] == '>')
    {
      if (i > 0 &&
	  ((cmd[i - 1] == '>' && cmd[i] == '<') ||
	   (cmd[i - 1] == '<' && cmd[i] == '>')))
      {
	write(2, "mysh: parse error near '", 24);
	write(2, &(cmd[i]), 1);
	write(2, "'\n", 2);
	return (-1);
      }
      ret = 1;
    }
    i++;
  }
  return (ret);
}

void	do_exec(char *cmd, t_env **my_env, char **env_tab)
{
  char	**cmd_tab;
  pid_t	ps;
  t_cmd	*my_cmd;
  int	multiple;
  int	redirect;

  my_cmd = NULL;
  if (!(multiple = check_multiple_cmd(cmd, &my_cmd)))
    return ;
  if ((redirect = check_redirection(cmd)) == -1)
    return ;
  
  if ((cmd_tab = check_cmd(cmd, my_env, env_tab)))
  {
    ps = fork();
    if (ps == 0)
      exec_cmd(cmd_tab, my_env, env_tab);
    else if (ps < 0)
      my_putstrerror("Error fork.\n", 3);
    else
      wait(NULL);
  }
}
