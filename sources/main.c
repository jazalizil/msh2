/*
** main.c for sources in /share/projets/sysunix/msh2/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Thu May 23 14:21:30 2013 jalil dabbech
** Last update mer. juil. 17 06:40:36 2013 jalil dabbech
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "mysh.h"
#include "my.h"

int	my_conv_env(t_env **my_env, char **envp)
{
  int	i;
  int	j;
  int	tmp;
  char	*var;
  char	*value;

  i = 0;
  j = 0;
  *my_env = NULL;
  while (envp[i])
  {
    j = 0;
    while (envp[i][j] != '=')
      j++;
    var = my_strndup(envp[i], 0, j++);
    tmp = j;
    while (envp[i][j])
      j++;
    value = my_strndup(envp[i], tmp, j);
    *my_env = my_put_in_list(*my_env, var, value);
    i++;
  }
  return (i);
}

char	*node_to_char(t_env *env_var)
{
  char	*ret;
  int	size;
  int	i;
  int	j;

  size = my_strlen(env_var->var) + my_strlen(env_var->value) + 1;
  ret = my_malloc(size, "node_to_char. \n");
  i = 0;
  while (env_var->var[i])
  {
    ret[i] = env_var->var[i];
    i++;
  }
  ret[i] = '=';
  i++;
  j = 0;
  while (env_var->value[j])
  {
    ret[i] = env_var->value[j];
    i++;
    j++;
  }
  return (ret);
}

char	**my_cpy_env(t_env **my_env, int size)
{
  char	**ret;
  int	i;

  ret = my_wordtabmalloc(size + 1, "copy env");
  i = 0;
  while (i < size)
  {
    ret[i] = node_to_char(*my_env);
    my_env = &((*my_env)->next);
    i++;
  }
  ret[i] = NULL;
  return (ret);
}

int	main(int ac, char **av, char **envp)
{
  char	**env_cp;
  t_env	*my_env;
  int	size;

  if (ac != 1 || av[1])
  {
    write(2, "Usage: ./mysh\n", 14);
    return (-1);
  }
  size = my_conv_env(&my_env, envp);
  env_cp = my_cpy_env(&my_env, size);
  signal(SIGINT, get_sigint);
  do_sh(&my_env, env_cp);
  return (0);
}
