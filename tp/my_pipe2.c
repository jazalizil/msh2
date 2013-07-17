#include <unistd.h>

int	main()
{
  int	fild[2];
  int	pid;
  char	buff[512];
  int	len;

  if (pipe(fild) == -1)
    return (-1);
  if ((pid = fork()) == -1)
    return (-1);
  else if (pid == 0)
  {
    close(fild[0]);
    dup2(fild[1], 1);
    write(1, "salut depuis fild0\n", 19);
  }
  else
  {
    close(fild[1]);
    len = read(fild[0], buff, 511);
    buff[len] = 0;
    write(1, "J'ai lu: ", 9);
    write(1, buff, len);
  }
  return (0);
}
