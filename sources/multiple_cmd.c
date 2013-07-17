/*
** multiple_cmd.c for sources in /share/projets/sysunix/msh2/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  mer. juil. 17 07:46:30 2013 jalil dabbech
** Last update mer. juil. 17 08:50:32 2013 jalil dabbech
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>

void	multiple_cmd(t_cmd **my_list, char *cmd)
{
  int	i;
  int	j;

  i = 0;
  while (cmd[i])
  {
    j = i;
    while (cmd[i] && cmd[i] != ';')
      i++;
    add_cmd(my_list, my_strndup(cmd, j, i));
    i++;
  }
}
