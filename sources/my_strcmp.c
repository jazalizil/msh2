/*
** my_strcmp.c for sources in /home/dabbec_j/projets/minishell1-2017pso-dabbec_j/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Wed May 22 19:01:21 2013 jalil dabbech
** Last update Fri Jun 07 12:23:44 2013 jalil dabbech
*/

#include "mysh.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i])
  {
    if (s1[i] == '\0')
      return (0);
    i = i + 1;
  }
  return (s1[i] - s2[i]);
}
