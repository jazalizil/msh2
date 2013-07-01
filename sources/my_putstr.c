/*
** my_putstr.c for sources in /home/dabbec_j/projets/minishell1/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Wed May 22 19:08:14 2013 jalil dabbech
** Last update Wed May 22 19:23:41 2013 jalil dabbech
*/

#include <unistd.h>
#include "mysh.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}
