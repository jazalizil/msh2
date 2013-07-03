/*
** whereiscmd.c for sources in /Volumes/Jazalizil/Utilisateurs/jazalizil/msh2/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Thu May 23 15:57:56 2013 jalil dabbech
** Last update Jeu jul 04 01:05:25 2013 jalil dabbech
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"

int	how_many_rep(char *path)
{
  int	ret;
  int	i;

  ret = 0;
  i = 0;
  while (path[i])
  {
    if (path[i] == ':')
      ret++;
    i++;
  }
  return (ret);
}

char	**separe_path(char *path)
{
  char	**ret;
  int	many_rep;
  int	i;
  int	previous_pos;
  int	j;

  ret = my_wordtabmalloc((many_rep = how_many_rep(path) + 1), "pos_colon.\n");
  i = 0;
  j = 0;
  previous_pos = 0;
  while (path[i])
  {
    if (path[i] == ':' || (!path[i + 1] && path[i] != ':'))
    {
      if (!path[i + 1])
	i ++;
      ret[j] = my_strndup(path, previous_pos, i);
      previous_pos = i + 1;
      j++;
    }
    i++;
  }
  ret[j] = NULL;
  return (ret);
}

char		*which_rep(char **path, char *cmd)
{
  DIR		*rep;
  int		i;
  struct dirent	*files;

  i = 0;
  while (path[i])
  {
    if ((rep = opendir(path[i])))
    {
      while ((files = readdir(rep)))
	if (my_strcmp(files->d_name, cmd) == 0)
	  return (path[i]);
      closedir(rep);
    }
    i++;
  }
  return (NULL);
}

char	*my_concat(char *str1, char *str2, char separator)
{
  char	*ret;
  int	size;
  int	i;
  int	j;

  size = my_strlen(str1) + my_strlen(str2) + 2;
  if (!(ret = my_malloc(size, "my_concat.\n")))
    return (NULL);
  i = 0;
  while (str1[i])
  {
    ret[i] = str1[i];
    i++;
  }
  ret[i] = separator;
  i++;
  j = 0;
  while (str2[j])
  {
    ret[i] = str2[j];
    j++;
    i++;
  }
  ret[i] = '\0';
  return (ret);
}

char	*where_is_cmd(char *cmd, t_env **my_env)
{
  char	**path_tab;
  char	*path;

  path_tab = NULL;
  while (*my_env)
  {
    if (my_strcmp((*my_env)->var, "PATH") == 0)
      path_tab = separe_path((*my_env)->value);
    my_env = &((*my_env)->next);
  }
  if (!(path = which_rep(path_tab, cmd)) || path_tab == NULL)
  {
    write(2, "mysh: command not found: ", 25);
    write(2, cmd, my_strlen(cmd));
    write(2, "\n", 1);
    exit(EXIT_FAILURE);
  }
  return (my_concat(path, cmd, '/'));
}
