#include <stdio.h>

int main()
{
  union Data
  {
    int a;
    char b;
  }data;

  data.a = 1;
  if(1 == data.b)
  {
    printf("小端\n");
  }
  else
  {
    printf("大端\n");
  }
  return 0;
}
