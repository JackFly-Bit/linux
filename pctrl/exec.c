#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  pid_t pid = fork();
  if (0 == pid){
    //子进程
    //让子进程运行当前路径下的a程序
    //execl("./a", "a", "-l", "-p", "zhang", NULL);
    //char* child_argv[32];
    //child_argv[0] = "a";
    //child_argv[1] = "-r";
    //child_argv[2] = "wen";
    //child_argv[3] = NULL;
    //execv("./a", child_argv);
    char* env[32] = {NULL};
    env[0] = "MYVAL = 1000";
    env[1] = "TMP = 100";
    env[2] = NULL;
    execle("./a", "ls", "-l", NULL, env);
  }else if(pid > 0){
    //父进程
  }
  printf("-------%d\n", getpid());
  return 0;
}
