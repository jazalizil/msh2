/*
** my_pwd.c for sources in /home/dabbec_j/projets/minishell2/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Thu Jun 27 17:29:11 2013 jalil dabbech
** Last update Mon Jul 01 17:31:39 2013 jalil dabbech
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void		do_the_rec(struct stat, struct stat, char *, char *);

void		my_stat(char *rep, struct stat *st)
{
  if (stat(rep, st) != 0)
  {
    my_putstrerror("Can not stat current dir.\n");
    exit(EXIT_FAILURE);
  }
}

DIR		*my_opendir(char *rep)
{
  DIR		*ret;

  if (!(ret = opendir(rep)))
  {
    my_putstrerror("Could not read directory content.\n");
    exit(EXIT_FAILURE);
  }
  return (ret);
}

char		*my_getcw()
{
  struct stat	current;
  struct stat	parent;
  char		*found_dir;
  char		*ret;
  int		len_ret;
  int		len_found;

  my_stat(".", &current);
  chdir("..");
  my_stat(".", &parent);
  do_the_rec(current, parent, found_dir, ret);
  len_ret = my_strlen(ret);
  write(1, "a\n", 2);
  if (len_ret != 1)
    my_strcat(ret, "/");
  if (found_dir)
  {
    len_found = my_strlen(found_dir);
    my_strncat(ret, found_dir, len_found);
    free(found_dir);
  }
  return (ret);
}

void		do_the_rec(struct stat current, struct stat parent,
    				char *found_dir, char *ret)
{
  int		found;
  struct stat	tmp;
  struct dirent	*rep;
  DIR		*dir;

  found = 0;
  dir = my_opendir(".");
  if ((current.st_dev == parent.st_dev) && (current.st_ino == parent.st_ino))
  {
    ret = my_malloc(FILENAME_MAX, "malloc\n");
    ret[0] = 0;
    found_dir = NULL;
  }
  else
  {
    while ((rep = readdir(dir)) && !found)
    {
      my_stat(rep->d_name, &tmp);
      if ((tmp.st_dev == current.st_dev) && (tmp.st_ino == current.st_ino))
	found = 1;
    }
    found_dir = my_strdup(rep->d_name);
    closedir(dir);
    ret = my_getcw();
  }
}

int	main()
{
  my_putstr(my_getcw());
  write(1, "\n", 1);
  return (0);
}
