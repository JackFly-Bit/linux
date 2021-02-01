#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
  close(0);
  int fd = open("./linux", O_RDWR | O_CREAT, 0664);
  if(fd < 0)
  {
    perror("open");
    return -1;
  }
  printf("%d\n", O_RDWR | O_CREAT);
  printf("fd : %d\n", fd);

  while(1)
  {
    sleep(1);
  }

  return 0;
}
