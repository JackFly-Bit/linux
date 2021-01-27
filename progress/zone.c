#include <stdio.h>
#include <unistd.h>

int g_val = 100;
int main()
{
  pid_t pid = fork();//创建子进程
  if(pid < 0){
    printf("fork error");
    return -1;
  }else if (0 == pid){
    //这是子进程才能运行的代码
    g_val = 200;
    printf("this is child ---g_val:%d-%p\n", g_val, &g_val);
  }else if (pid > 0){
    //这是父进程才能运行的代码
    sleep(1);
    printf("this is parent ---g_val:%d-%p\n", g_val, &g_val);
  }
  //这里的代码父子进程都会运行
  return 0;
}
