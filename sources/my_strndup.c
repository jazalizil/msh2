/*
** my_strndup.c for sources in /home/dabbec_j/projets/minishell1-2017pso-dabbec_j/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Mon May 27 17:02:28 2013 jalil dabbech
** Last update Thu Jun 06 18:57:47 2013 jalil dabbech
*/

#include <unistd.h>
#include "mysh.h"

char	*my_strdup(char *src)
{
  char	*ret;
  int	i;

  i = 0;
  if (!(ret = my_malloc(my_strlen(src), "my_strdup.\n")))
    return (NULL);
  while (src[i])
  {
    ret[i] = src[i];
    i++;
  }
  ret[i] = '\0';
  return (ret);
}

char	*my_strndup(char *src, int start, int end)
{
  char	*ret;
  int	i;

  if ((ret = my_malloc(end - start + 1, "my_conv_env.\n")) == NULL)
    return (NULL);
  i = 0;
  while (start < end)
  {
    ret[i] = src[start];
    i++;
    start++;
  }
  ret[i] = '\0';
  return (ret);
}
