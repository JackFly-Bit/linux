#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigcallback(int signo)
{
  printf("signo : %d\n", signo);
}

int main()
{
  signal(2, sigcallback);
  signal(20, sigcallback);

  while(1)
  {
    printf("linux so esay\n");
    sleep(1);
  }
  return 0;
}
