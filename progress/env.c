#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[], char* env[])
{
  //argc 是程序运行参数的个数
  //argv[] 是用于指向程序中各个环境变量的一个字符串指针数组
  //./env -l -a  [./env]就是第0个参数:[./env]就是第一个参数 [-a]就是第二个参数
  //env[] 是用于指向程序中各个环境变量的一个字符串指针数组
  int i;
  for(i = 0; i < argc; i++){
    printf("argv[%d]=[%s]\n", i, argv[i]);
  }
//getenv(),通过环境变量名称获取环境变量数据，通过返回值返回，若没有这个环境变量返回NULL
  char* tmp = getenv("MYVAL");
  if (NULL == tmp){
    printf("have no env var:MYVAL\n");
  }else{
    printf("MYVAL:[%s]\n",tmp);
  }
  extern char** environ;//声明变量，注意这个变量在库中有，只需要声明就能使用
//  int i;
//  for(i = 0; environ[i] != NULL; i++){
//    printf("environment: [%s]\n", environ[i]);
//  }

//  int i;
//  for(i = 0; env[i] != NULL; i++){
//    printf("environment: [%s]\n", env[i]);
//  }
  
//  while(1){
//    sleep(1);
//  }
  return 0;
}
