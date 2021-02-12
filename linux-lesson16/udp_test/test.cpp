#include <stdio.h>
#include <unistd.h>

//网络编程
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
  //创建套接字
  int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if(sockfd < 0)
  {
    perror("socket");
    return -1;
  }

  //绑定地址信息
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  //1.将点分十进制的ip地址转化成为uint32_t
  //2.将uint32_t从主机字节序转换成为网络字节序
  // htonl()//只能完成第二件事情
  addr.sin_addr.s_addr = inet_addr("192.168.73.129");//ip
  addr.sin_port = htons(19999);
  int ret = bind(sockfd,(struct sockaddr*)&addr, sizeof(addr));
  if(ret < 0)
  {
    perror("bind");
    return -1;
  }

  while(1)
  {
    sleep(1);
  }
  return 0;
}
