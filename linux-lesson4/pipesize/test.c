#include <stdio.h>
#include <unistd.h>

int main()
{
  int fd[2];
  int ret = pipe(fd);
  if(ret < 0)
  {
    perror("pipe");
    return -1;
  }
  else if(0 == ret)
  {
    //child
  }
  else{
    //father
  }

  int count = 0;
  while(1)
  {
    write(fd[1], "h", 1); 
    count++;
    printf("count: %d\n", count);
  }
  return 0;
}
