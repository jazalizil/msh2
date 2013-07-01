/*
** my_malloc.c for sources in /home/dabbec_j/projets/minishell2/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Dim mai 05 13:33:26 2013 jalil dabbech
** Last update Mon Jul 01 16:37:01 2013 jalil dabbech
*/

#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"

void	*my_malloc(int size, char *when)
{
  void	*ret;

  ret = malloc(size * sizeof(char));
  if (ret == NULL)
  {
    my_putmlkerror("Error malloc in ");
    my_putmlkerror(when);
    exit(EXIT_FAILURE);
  }
  return (ret);
}

char	**my_wordtabmalloc(int size, char *when)
{
  char	**ret;

  ret = malloc(size * sizeof(char *));
  if (ret == NULL)
  {
    my_putmlkerror("Error malloc in ");
    my_putmlkerror(when);
  }
  return (ret);
}

int	my_wordtab_size(char **wordtab)
{
  int	i;

  i = 0;
  while (wordtab[i])
    i++;
  return (i);
}

void	my_free_wordtab(char **wordtab, int size)
{
  int	i;

  i = 0;
  while (i < size)
    free(wordtab[i++]);
  free (wordtab);
}
