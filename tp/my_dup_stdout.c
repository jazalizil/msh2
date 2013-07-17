#include <unistd.h>
#include <fcntl.h>

int	main()
{
  int	fd;

  fd = open("./fic", O_WRONLY);
  dup2(fd, 1);
  write(1, "bonjour\n", 8);
  return (0);
}
