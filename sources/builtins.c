/*
** builtins.c for sources in /home/dabbec_j/projets/minishell2/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Sat May 25 17:07:45 2013 jalil dabbech
** Last update Thu Jun 27 18:18:36 2013 jalil dabbech
*/

#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

int	do_cd(char **cmd, t_env **my_env)
{
  if (cmd[1])
  {
    if (chdir(cmd[1]) < 0)
    {
      write(2, cmd[1], my_strlen(cmd[1]));
      write(2, ": No such file or directory.\n", 29);
    }
  }
  else
  {
    while (*my_env)
    {
      if (my_strcmp((*my_env)->var, "HOME") == 0)
	if (chdir((*my_env)->value) < 0)
	{
	  write(2, (*my_env)->value, my_strlen((*my_env)->value));
	  write(2, ": No such file or directory.\n", 29);
	}
      my_env = &((*my_env)->next);
    }
  }
  return (1);
}

int	do_setenv(char **cmd, t_env **my_env)
{
  char	*var;
  char	*value;
  int	i;

  i = 0;
  if (cmd[1])
    while (cmd[1][i])
    {
      if (cmd[1][i] == '=')
      {
	var = my_strndup(cmd[1], 0, i);
	value = my_strndup(cmd[1], i + 1, my_strlen(cmd[1]));
	if (!is_in_env(var, value, my_env))
	  *my_env = my_put_in_list(*my_env, var, value);
	else
	  return (0);
	return (1);
      }
      i++;
    }
  else
    write(2, "Usage: setenv VAR=VALUE\n", 24);
  return (0);
}

int	do_unsetenv(char **cmd, t_env **my_env)
{
  t_env	*tmp;

  tmp = NULL;
  if (cmd[1])
    while (*my_env)
    {
      if (my_strcmp((*my_env)->var, cmd[1]) == 0)
      {
	tmp = (*my_env);
	(*my_env) = tmp->next;
	free(tmp->value);
	free(tmp->var);
	free(tmp);
	return (1);
      }
      my_env = &((*my_env)->next);
    }
  write(2, "Usage: unsetenv VAR (from env)\n", 31);
  return (0);
}

int	do_env(char **cmd, t_env **my_env)
{
  if (cmd)
  {
    while (*my_env)
    {
      my_putstr((*my_env)->var);
      my_putchar('=');
      my_putstr((*my_env)->value);
      my_putchar('\n');
      my_env = &((*my_env)->next);
    }
    return (1);
  }
  return (0);
}

int	do_exit(char **cmd, t_env **my_env)
{
  if (cmd)
  {
    stop_the_shell(my_env, 0);
    return (1);
  }
  return (0);
}
