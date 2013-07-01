/*
** my_puterror.c for sources in /home/dabbec_j/projets/minishell1/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Sam mai 04 15:27:11 2013 jalil dabbech
** Last update Tue May 21 17:36:55 2013 jalil dabbech
*/

#include <unistd.h>
#include <stdlib.h>

int	my_strlen(char *);

void	my_putcharerror(char c)
{
  write(2, &c, 1);
}

void	my_putstrerror(char *str, int code)
{
  int	i;

  i = 0;
  while (str[i])
  {
    my_putcharerror(str[i]);
    i ++;
  }
  exit(code);
}

void	my_putmlkerror(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    my_putcharerror(str[i++]);
}
