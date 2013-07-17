/*
** my_fork.c for sources in /share/projets/sysunix/msh2/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  mer. juil. 17 07:50:18 2013 jalil dabbech
** Last update mer. juil. 17 09:11:59 2013 jalil dabbech
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"
#include "my.h"

int	many_pipes(char	**cmd_tab)
{
  int	i;
  int	ret;

  i = 0;
  ret = 0;
  while (cmd_tab[i])
  {
    if (cmd_tab[i][0] == '|')
      ret++;
    i++;
  }
  return (ret);
}

void	get_cmds(t_cmd **cmds, char *cmd)
{
  int	i;
  int	j;

  i = 0;
  while (cmd[i])
  {
    j = i;
    while (cmd[i] && cmd[i] != '|')
      i++;
    revadd_cmd(cmds, my_strndup(cmd, j, i));
    i++;
  }
}

void	do_the_fork(cmd)
{
}

void	my_fork(char *cmd, t_env **my_env, char **env_tab)
{
  int	ps;
  t_cmd	*cmds;
  char	**cmd_tab;

  cmds = NULL;
  get_cmds(&cmds, cmd);
  while (cmds)
  {
    my_putstr(cmds->cmd);
    write(1, "\n", 1);
    cmds = cmds->next;
  }
  exit(0);
  if ((cmd_tab = check_cmd(cmds->cmd, my_env, env_tab)))
  {
    ps = fork();
    if (ps == 0)
      exec_cmd(cmd_tab, my_env);
    else if (ps == -1)
      my_putstrerror("Error fork.\n", EXIT_FAILURE);
    else
      wait(NULL);
  }
}
