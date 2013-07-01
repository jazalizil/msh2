##
## Makefile for minishell2 in /home/dabbec_j/projets/minishell2
## 
## Made by jalil dabbech
## Login   <dabbec_j@epitech.net>
## 
## Started on  Tue May 21 14:07:58 2013 jalil dabbech
## Last update Mon Jul 01 17:40:27 2013 jalil dabbech
##

NAME	=	mysh

SRC	=	sources/get_next_line.c \
		sources/main.c \
		sources/my_list.c \
		sources/my_malloc.c \
		sources/my_puterror.c \
		sources/my_putstr.c \
		sources/my_str_to_wordtab.c \
		sources/my_strcmp.c \
		sources/mysh.c \
		sources/whereiscmd.c \
		sources/builtins.c \
		sources/errors.c \
		sources/manage_builtins.c \
		sources/my_strndup.c \
		sources/manage_sig.c \
		sources/check_setenv.c \
		sources/my_strcat.c \
		sources/exec.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -W -Wall -Werror -pedantic -Wextra -Iincludes

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
