/*
** my_strcat.c for sources in /home/dabbec_j/projets/minishell2/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Mon Jul 01 17:01:33 2013 jalil dabbech
** Last update Mon Jul 01 17:18:03 2013 jalil dabbech
*/

#include "mysh.h"

char    *my_strcat(char *dest, char *src)
{
  int   i;
  int   j;

  j = 0;
  i = my_strlen(dest);
  while (src[j])
    dest[i++] = src[j++];
  dest[i] = '\0';
  return (dest);
}

char	*my_strncat(char *dest, char *src, int n)
{
  int	dest_len;
  int	i;

  dest_len = my_strlen(dest);
  i = 0;
  while (i < n && src[i])
  {
    dest[dest_len + i] = src[i];
    i++;
  }
  dest[dest_len + i] = '\0';
  return (dest);
}
