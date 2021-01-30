#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void function(){
  printf("^^^^^^^^^^");
//  printf("^^^^^^^^^^\n");
  exit(0);
//  _exit(0); 
//  return;
  printf("@@@@@@@@@@\n");
}
int main()
{
  char tmp[10] = {0};
  for(int i = 0; i < 10; i++){
    tmp[i] = '-';
//    printf("%s\r", tmp);
    printf("%s", tmp);
//    fflush(stdout);//刷新缓冲区
    usleep(100000);
//    printf("%s\n", tmp);
  }
  printf("----------\n");
  function();
  printf("**********\n");
//return 0;
//printf("**********\n");
}
