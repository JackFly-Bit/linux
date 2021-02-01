#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
  int fd = open("./linux", O_RDWR | O_CREAT, 0664);
  if(fd < 0)
  {
    perror("open");
    return -1;
  }
  printf("%d\n", O_RDWR | O_CREAT);
  printf("fd : %d\n", fd);

  write(fd, "linux-57", 8);
  lseek(fd, 0, SEEK_SET);
  char buf[1024] = {0};
  read(fd, buf, sizeof(buf) - 1);
  printf("buf-%s\n", buf);
  //探讨文件描述符
  close(fd);

  return 0;
}
