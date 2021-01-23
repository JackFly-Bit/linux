#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "d.h"

//测试函数
void test(){
  char* tmp = NULL;
  strcpy(tmp, "hello world!");
  return;
}
int main()
{
 // b = 10;
  int a = 1;
  if(a > 2){
    a = 0;
  }else{
    a = 2;
  }
  print_child();
  for(int a = 1; a < 5; a++){
    printf("hello world!\n");
    sleep(1);
  }
  test();
  return 0;
}
