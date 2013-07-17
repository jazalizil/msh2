#include <unistd.h>
#include "get_next_line.h"

int		main()
{
  static int	fild[2];
  int		pid;

  if (pipe(fild) == -1)
    return (-1);
  if ((pid = fork()) == -1)
    return (-1);
  else if (pid == 0)
  {
    close(fild[0]);
    dup2(fild[1], 1);
    execlp("/bin/ls", "ls", 0);
  }
  else
  {
    close(fild[1]);
    dup2(fild[0], 0);
    execlp("/bin/more", "most", 0);
  }
  return (0);
}
