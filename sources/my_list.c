/*
** my_list.c for sources in /home/dabbec_j/projets/minishell2/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Tue May 21 18:43:05 2013 jalil dabbech
** Last update Mon Jul 01 18:19:52 2013 jalil dabbech
*/

#include <stdlib.h>
#include "mysh.h"

t_env	*my_put_in_list(t_env *my_env, char *env_var, char *env_value)
{
  t_env	*new;
  t_env	*tmp;

  if ((new = my_malloc(sizeof(t_env), "malloc t_env")) == NULL)
    exit(EXIT_FAILURE);
  new->var = env_var;
  new->value = env_value;
  new->next = NULL;
  if (my_env == NULL)
  {
    my_env = new;
    return (new);
  }
  tmp = my_env;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = new;
  return (my_env);
}

void	my_put_cmd(t_cmd **my_list, char *cmd)
{
  t_cmd	*new;

  if ((new = my_malloc(sizeof(t_cmd), "malloc t_cmd.\n")) == NULL)
    exit(EXIT_FAILURE);
  new->cmd = cmd;
  new->next = NULL;
  if (!(*my_list))
    *my_list = new;
  else
  {
    while ((*my_list)->next)
      my_list = &((*my_list)->next);
    (*my_list)->next = new;
  }
}


void	my_free_list(t_env *my_env)
{
  if (my_env)
  {
    free(my_env->var);
    free(my_env->value);
    my_free_list(my_env->next);
  }
  free(my_env);
}
