#include <stdio.h>
#include <unistd.h>

int main()
{
  pid_t pid = fork();//返回的是子进程的pid
  if(pid < 0)
  {
    perror("fork");
    return -1;
  }else if( 0 == pid ){
    //child
    printf("i am child, pid = %d, ppid = %d\n", getpid(), getppid());
  }else 
  {
    //father
    printf("i am father, pid = %d, ppid = %d\n", getpid(), getppid());
  }
  while(1)
  {
    sleep(1);
  }
  return 0;
}
