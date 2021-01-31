#include <stdio.h>
#include <unistd.h>

int main()
{
  printf("hehehehehe\n");
  //execv
  execl("/usr/bin/pwd", "pwd",  NULL);
  //代码可以执行到这里，说明替换失败了
  while(1)
  {
    printf("57-linux\n");
    sleep(1);
  }
    return 0;
}
