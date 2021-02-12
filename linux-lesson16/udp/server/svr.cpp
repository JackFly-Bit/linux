#include <stdio.h>
#include <unistd.h>
//网络编程
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <iostream>
#include <string>

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
    //  htonl() // 只能完成第二件事情
    addr.sin_addr.s_addr = inet_addr("172.16.99.129");//ip;
    addr.sin_port = htons(19999);

    
    int ret = bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    if(ret < 0)
    {
        perror("bind");
        return -1;
    }

    while(1)
    {
        char buf[1024] = { 0 };
        struct sockaddr_in peer_addr;
        socklen_t peer_addr_len = sizeof(peer_addr);
        //socklen_t peer_addr_len;
        ssize_t recv_size = recvfrom(sockfd, buf, sizeof(buf) - 1, 0, (struct sockaddr*)&peer_addr, &peer_addr_len);
        if(recv_size < 0)
        {
            perror("recvfrom");
            continue;
        }
        printf("cli say: %s\n", buf);

        //1.已经拥有了发送方的地址信息结构和地址信息长度
        //2.组织要返回给发送方的数据， 并且调用sendto
        std::string s;
        std::cin >> s;

        ssize_t send_size = sendto(sockfd, s.c_str(), s.size(), 0, (struct sockaddr*)&peer_addr, peer_addr_len);
        if(send_size < 0)
        {
            perror("sendto");
            continue;
        }
    }

    close(sockfd);
    return 0;
}
