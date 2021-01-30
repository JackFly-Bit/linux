#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
  pid_t pid = fork();
  if (0 == pid){
//    sleep(5);
    exit(0);
  }else if(pid > 0){
    while(1){
    sleep(5);
      wait(NULL);//等待子进程退出
      printf("正在打麻将~~\n");
      sleep(1);
    }
  }
  return 0;
}
