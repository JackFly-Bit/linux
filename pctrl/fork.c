#include <stdio.h>
#include <unistd.h>

int main()
{
  pid_t pid = vfork();
  if (pid < 0){
    printf("vfork error\n");
    return -1;
  }else if (0 == pid){
    sleep(3);
    printf("this is child!\n");
  }else if(pid >0){
    printf("this is parents\n");
  }
  printf("-----------\n");
}
