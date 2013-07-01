/*
** my_str_to_wordtab.c for sources in /home/dabbec_j/projets/minishell1-2017pso-dabbec_j/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Mon Jun 03 21:29:08 2013 jalil dabbech
** Last update Mon Jun 03 21:30:05 2013 jalil dabbech
*/

#include <stdlib.h>
#include "mysh.h"

int	how_many_words(char *str)
{
  int	ret;
  int	i;

  ret = 0;
  i = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i])
  {
    if (str[i] == ' ' || str[i] == '\t' || str[i + 1] == '\0')
    {
      ret++;
      while (str[i + 1] == ' ' || str[i + 1] == '\t')
	i++;
    }
    i++;
  }
  return (ret);
}

char	*cp_word(char *str, int *pos, int *pos_init)
{
  char	*ret;

  if (str[*pos + 1] == '\0')
    ret = my_strndup(str, *pos_init, *pos + 1);
  else
    ret = my_strndup(str, *pos_init, *pos);
  while (str[*pos + 1] == ' ' || str[*pos + 1] == '\t')
    *pos += 1;
  *pos_init = *pos + 1;
  return (ret);
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	j;
  int	pos_init;
  char	**ret;

  i = 0;
  j = 0;
  ret = my_wordtabmalloc(how_many_words(str) + 1, "str_to_wordtab.\n");
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  pos_init = i;
  while (str[i])
  {
    if (str[i] == ' ' || str[i] == '\t' || str[i + 1] == '\0')
    {
      ret[j] = cp_word(str, &i, &pos_init);
      j++;
    }
    i++;
  }
  ret[j] = NULL;
  return (ret);
}
