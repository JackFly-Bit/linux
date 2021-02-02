#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>                   
                                        
int main()                            
{  
  int count = 0;
  while(1)
  {
    int fd = open("./linux", O_CREAT | O_RDWR, 0664);
    if(fd < 0)
    {
      perror("open");
      break;
    }
    count++;
    printf("fd : %d\n", fd);
  }
  //1021(1024 - stdin, stdout, strerr)
    printf("count : %d\n", count);
 return 0;                           
}  
