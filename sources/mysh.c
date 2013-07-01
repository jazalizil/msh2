/*
** mysh.c for sources in /home/dabbec_j/projets/minishell2/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Mon Jun 03 21:18:52 2013 jalil dabbech
** Last update Mon Jul 01 18:59:58 2013 jalil dabbech
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "mysh.h"
#include "get_next_line.h"

static int	stop;
static char	**env_tab;


void	stop_the_shell(t_env **my_env, int eof_or_exit)
{
  if (eof_or_exit)
    my_putchar('\n');
  stop = 1;
  my_free_list(*my_env);
  my_free_wordtab(env_tab, my_wordtab_size(env_tab));
}

void	set_env_tab(t_env **env, int size)
{
  my_free_wordtab(env_tab, my_wordtab_size(env_tab));
  env_tab = my_cpy_env(env, size);
}

void	do_sh(t_env **my_env, char **my_env_tab)
{
  char	*cmd;

  env_tab = my_env_tab;
  while (!stop)
  {
    my_putstr("$> ");
    cmd = NULL;
    if ((cmd = get_next_line(0)))
      do_exec(cmd, my_env, env_tab);
    else
      stop_the_shell(my_env, 1);
  }
}
