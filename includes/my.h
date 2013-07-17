/*
** my.h for includes in /share/projets/sysunix/msh2/includes
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Tue Jun 18 16:27:41 2013 jalil dabbech
** Last update mer. juil. 17 09:12:02 2013 jalil dabbech
*/

#ifndef MY_H_
# define MY_H_

void		*my_malloc(int, char *);
void		my_putmlkerror(char *);
int		my_strcmp(char *, char *);
void		my_putstrerror(char *, int);
char		**my_wordtabmalloc(int, char *);
void		my_free_wordtab(char **, int);
int		my_getnbr(char *);
void		my_putcharerror(char);
void		my_putstrerror(char *, int);
void		my_putmlkerror(char *);
char		*my_strndup(char *, int, int);
void		my_putstr(char *);
void		my_putchar(char);
unsigned int	my_strlen(const char *);
void		my_free_wordtab(char **, int);
int		my_wordtab_size(char **);
char		*my_strdup(char *);
char		**my_str_to_wordtab(char *);

#endif /* !MY_H_ */
