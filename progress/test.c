#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  pid_t pid = fork();
  if(pid > 0){
    //parents
    printf("parents:%d\n",getpid());
    sleep(3);
    exit(0);
  }else if(0 == pid){
    //child
    printf("child:%d\n",getpid());
  }else{
    //error
    exit(0);
  }
  printf("--------------%d\n",getpid());
  while(1){
  sleep(10000);//因为父进程直接exit退出，因此只有子进程会调用sleep()
  }

//  int a = 0;
//  while(++a) sleep(1) ;
  return 0;
}
