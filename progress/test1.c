#include <stdio.h>

void test_print(int a)
{
  printf(a);
}
int main(int argc, char* argv[])
{
  test_print(10, 20);
  return 0;
}
