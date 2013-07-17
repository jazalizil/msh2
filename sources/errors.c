/*
** errors.c for sources in /share/projets/sysunix/msh2/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Mon May 27 15:33:07 2013 jalil dabbech
** Last update mer. juil. 17 08:23:56 2013 jalil dabbech
*/

#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"
#include "my.h"

void	check_error(char **cmd, char **arg)
{
  if (access(cmd[0], X_OK) < 0)
  {
    write(2, cmd[0], my_strlen(cmd[0]));
    write(2, ": Permission denied", 19);
  }
  else
  {
    write(2, cmd[0], my_strlen(cmd[0]));
    write(2, ": Unknow error", 14);
  }
  my_free_wordtab(cmd, my_wordtab_size(cmd));
  my_free_wordtab(arg, my_wordtab_size(arg));
  exit(EXIT_FAILURE);
}
