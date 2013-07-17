/*
** mysh.c for sources in /share/projets/sysunix/msh2/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Mon Jun 03 21:18:52 2013 jalil dabbech
** Last update mer. juil. 17 09:12:00 2013 jalil dabbech
*/

#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"
#include "my.h"
#include "get_next_line.h"

static int	stop;
static char	**env_tab;

char	**assign_args(char **cmd_tab)
{
  int	i;
  char	**ret;

  i = 0;
  while (cmd_tab[i])
    i++;
  ret = my_wordtabmalloc(i, "assign_args. \n");
  i = 0;
  while (cmd_tab[i])
  {
    ret[i] = my_strdup(cmd_tab[i]);
    i++;
  }
  ret[i] = NULL;
  return (ret);
}

void	exec_cmd(char **cmd_tab, t_env **my_env)
{
  char	**arg;

  arg = assign_args(cmd_tab);
  if (execve(cmd_tab[0], arg, env_tab) == -1)
  {
    cmd_tab[0] = where_is_cmd(cmd_tab[0], my_env);
    arg = assign_args(cmd_tab);
    if ((execve(cmd_tab[0], arg, env_tab)) == -1)
      check_error(cmd_tab, arg);
  }
  my_free_wordtab(arg, my_wordtab_size(arg));
  my_free_wordtab(cmd_tab, my_wordtab_size(cmd_tab));
  exit(EXIT_SUCCESS);
}

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
  char	**cmd_tab;
  t_cmd	*cmds;

  cmds = NULL;
  env_tab = my_env_tab;
  while (!stop)
  {
    my_putstr("$> ");
    if ((cmd = get_next_line(0)))
    {
      multiple_cmd(&cmds, cmd);
      while (cmds)
      {
	my_fork(cmds->cmd, my_env, env_tab);
	cmds = cmds->next;
      }
    }
    else
      stop_the_shell(my_env, 1);
  }
}
