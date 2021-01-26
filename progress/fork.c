#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  pid_t pid = fork();//创建子进程
  //因为子进程复制了父亲进程，因此子进程与父进程运行的代码以及运行的位置都是一样的
  //从代码运行的角度来看，就都是从fork函数之后开始运行的
  //因为父子进程运行的代码数据都一样，因此无法直接分辨，只能通过返回值判断
  //对于父进程fork返回值>0;对于子进程返回值==0
  //虽然父子进程代码相同，但是因为返回值不同，因此会各自进入不同的判断执行体
  if(pid > 0){
    //this is parents
    printf("this is parents:%d\n",getpid());
  }else if (0 == pid){
    //this is child
    printf("this is child:%d\n",getpid());//getpid()获取调用进程的标识符-pid-进程ID
    exit(0);//exit退出一个进程，谁调用就退出谁--当前这段代码只有子进程会运行
  }else{
    //error
   printf("error\n");
  }

  printf("this is progress\n");
  sleep(100);
  return 0;
}
