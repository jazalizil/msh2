#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char		*get_next_line(int);

int		main()
{
  int		fd;
  char		*line;

  fd = open("./fic", O_WRONLY);
  line = get_next_line(1);
  dup2(fd, 1);
  write(1, line, strlen(line));
  return (0);
}
