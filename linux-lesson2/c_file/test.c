#include <stdio.h>
#include <string.h>

int main()
{
  FILE* fp = fopen("./linux", "r+");
  if(!fp)
  {
    perror("fopen");
    return -1;
  }
  
  //char buf[1024] = {0};
  //ssize_t r_ret = fread(buf, 1, sizeof(buf) - 1, fp);
  //printf("r_ret:%d, --- %s\n", r_ret, buf);

  char buf[1024] = {0};
  strcpy(buf, "linux-57");
  ssize_t w_ret = fwrite(buf, 1, 9, fp);
  printf("w_ret:%d\n", w_ret);
  
  fseek(fp, 0, SEEK_SET);

   memset(buf, '\0', sizeof(buf));
  ssize_t r_ret = fread(buf, 1, sizeof(buf) - 1, fp);
  printf("r_ret:%d, --- %s\n", r_ret, buf);
  
  printf("open success\n");
  return 0;
}
