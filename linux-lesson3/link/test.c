#include <stdio.h>

void func(int* fd)
{
  printf("%d\n", *fd);
  *fd = 10;
}

void func1(int fd)
{

}
int main()
{
  int fd;
  func(&fd);
  func1(fd);

  printf("%d\n", fd);
  return 0;
}
