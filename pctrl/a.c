#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int g = 6;
int main(int argc, char* argv[], char* env[])
{
  //main函数有两个参数:第一个参数表示程的运行参数有多少个；第二个参数保存运行参数
  for(int i = 0; i < argc; i++){
    printf("argv[%d] = [%s]\n", i, argv[i]);
  }
  for(int i = 0; env[i] != NULL; i++){
    printf("env[%d] = [%s]\n", i, env[i]);
  }
  int var = 88;
  pid_t pid =  vfork();//vfork创建子进程，父进程公用虚拟地址空间
  if(pid < 0){
    printf("error");
  }else if(0 == pid){
    g++;
    var++;
    _exit(0);//退出会查看计数器，如果父进程没有退出，资源不会被释放
  }else if(pid > 0){
    printf("g = %d, var = %d\n", g, var);
  }
  return 0;
}
