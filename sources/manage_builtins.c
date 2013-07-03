/*
** manage_builtins.c for sources in /Volumes/Jazalizil/Utilisateurs/jazalizil/msh2/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Thu May 30 18:51:00 2013 jalil dabbech
** Last update Jeu jul 04 01:16:21 2013 jalil dabbech
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "mysh.h"

t_builtins	g_builtins[] =
{
  {"cd", &do_cd},
  {"setenv", &do_setenv},
  {"unsetenv", &do_unsetenv},
  {"env", &do_env},
  {"exit", &do_exit}
};

int	is_a_builtin(char *my_cmd)
{
  int	i;

  i = 0;
  while (i < 5)
  {
    if (my_cmd && my_strcmp(my_cmd, g_builtins[i].cmd) == 0)
      return (i);
    i++;
  }
  return (-1);
}

char	**check_cmd(char *cmd, t_env **my_env, char **env_tab)
{
  char	**cmd_tab;
  int	bi;
  int	ret;
  int	size;

  cmd_tab = my_str_to_wordtab(cmd);
  free(cmd);
  size = 0;
  while (cmd_tab[size])
  {
    if (cmd_tab[size][0] == '|')
      printf("pipe !\n");
    else if (cmd_tab[size][0] == ';')
      printf("and !\n");
    else
      printf("%s\n", cmd_tab[size]);
    size++;
  }
  exit(0);
  if ((bi = is_a_builtin(cmd_tab[0])) >= 0)
  {
    ret = g_builtins[bi].fct(cmd_tab, my_env);
    if ((bi == 2 || bi == 1) && ret == 1)
    {
      size = my_wordtab_size(env_tab);
      if (bi == 1)
	size++;
      else
	size--;
      set_env_tab(my_env, size);
    }
    my_free_wordtab(cmd_tab, my_wordtab_size(cmd_tab));
    return (NULL);
  }
  return (cmd_tab);
}
