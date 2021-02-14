#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>

int main()
{
    int listen_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(listen_sock < 0)
    {
        perror("socket");
        return -1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(19999);
    addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    int ret = bind(listen_sock, (struct sockaddr*)&addr, sizeof(addr));
    if(ret < 0)
    {
        perror("bind");
        return -1;
    }

    ret = listen(listen_sock, 5);
    if(ret < 0)
    {
        perror("listen");
        return -1;
    }

    int new_sock = accept(listen_sock, NULL, NULL);
    if(new_sock < 0)
    {
        perror("accept");
        return -1;
    }

    while(1)
    {
        char buf[1024] = {0};
        ssize_t recv_size = recv(new_sock, buf, sizeof(buf) - 1, 0);
        if(recv_size < 0)
        {
            perror("recv");
            continue;
        }
        else if(recv_size == 0)
        {
            printf("perr shutdown\n");
            close(new_sock);
            close(listen_sock);
            return 0;
        }

        printf("cli say: %s\n", buf);

        memset(buf, '\0', sizeof(buf));
        printf("please enter msg to cli: ");
        fflush(stdout);
        std::cin >> buf;

        //TODO
        //send()

    }
    return 0;
}
