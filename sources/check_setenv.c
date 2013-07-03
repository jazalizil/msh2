/*
** check_setenv.c for sources in /Volumes/Jazalizil/Utilisateurs/jazalizil/msh2/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Fri Jun 07 17:45:27 2013 jalil dabbech
** Last update Jeu jul 04 01:06:19 2013 jalil dabbech
*/

#include "mysh.h"

int	is_in_env(char *var_to_add, char *value_to_add, t_env **my_env)
{
  while (*my_env)
  {
    if (my_strcmp((*my_env)->var, var_to_add) == 0)
    {
      (*my_env)->value = my_concat((*my_env)->value, value_to_add, ':');
      return (1);
    }
    my_env = &((*my_env)->next);
  }
  return (0);
}
