#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

int main()
{
  kill(getpid(), SIGQUIT);
  int res = wait(NULL);
  if(res < 0){
    printf("%s\n", strerror(errno));//errno是一个全局变量--保存上一次系统调用的错误编号
    perror("wait error");
  }
  //for(int i = 0; i < 256; i++){
  //  printf("errmsg:%s\n", strerror(i));
  // }
  pid_t pid = fork();
  if (0 == pid){
    //child
    sleep(5);
    exit(256);
  }else if(pid > 0){
    //parent
    int status;
    while(0 == waitpid(pid, &status, WNOHANG)){//等待子进程退出
        printf("没有子进程退出,在学校门口抽根烟，然后再重新看放学没有\n");
        sleep(1);   
    }
    if (0 == (status & 0x7f)){
    printf("退出返回值:%d\n", (status>>8)&0xff);
    }
    if (WIFEXITED(status)){
    printf("退出返回值:%d\n", WEXITSTATUS(status));
    }
        while(1){
//      waitpid(pid, NULL, 0);
//      wait(NULL);//等待子进程退出
      printf("正在打麻将~~\n");
      sleep(1);
    }
  }
  return 0;
}
