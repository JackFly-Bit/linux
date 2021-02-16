#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <sstream>


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
    addr.sin_port = htons(19998);
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

    //当已完成连接队列为空的时候， 调用accept函数会阻塞
    int new_sock = -1;

    while(1)
    {

        new_sock = accept(listen_sock, NULL, NULL);
        if(new_sock < 0)
        {
            perror("accept");
            return -1;
        }

        char buf[1024] = {0};
        //MyTCPHeader mth;
        ssize_t recv_size = recv(new_sock, buf, sizeof(buf)-1, 0);
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

        //1.响应头部
        //类C风格
        //        
        //        snprintf(buf, sizeof(buf) - 1, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %lu\r\n\r\n", body.size());
        //
        std::string body = "<html>i love linux</html>";

        //std::stringstream ss;
        //ss << "HTTP/1.1 200 OK\r\n";
        //ss << "Content-Type: text/html\r\n";
        //ss << "Content-Length: " << body.size() << "\r\n";
        //ss << "\r\n";

        //std::stringstream ss;
        //ss << "HTTP/1.1 302 Location\r\n";
        //ss << "Content-Type: text/html\r\n";
        //ss << "Content-Length: " << body.size() << "\r\n";
        //ss << "Location: https://www.baidu.com/\r\n";
        //ss << "\r\n";

        //std::stringstream ss;
        //ss << "HTTP/1.1 404 Page Not Found\r\n";
        //ss << "Content-Type: text/html\r\n";
        //ss << "Content-Length: " << body.size() << "\r\n";
        //ss << "\r\n";

        std::stringstream ss;
        ss << "HTTP/1.1 502 Bad Gateway\r\n";
        ss << "Content-Type: text/html\r\n";
        ss << "Content-Length: " << body.size() << "\r\n";
        ss << "\r\n";

        ssize_t send_size = send(new_sock, ss.str().c_str(), ss.str().size(), 0);
        if(send_size < 0)
        {
            perror("send");
            continue;
        }

        send_size = send(new_sock, body.c_str(), body.size(), 0);
        if(send_size < 0)
        {
            perror("send");
            continue;
        }

    }

    close(new_sock);
    close(listen_sock);
    return 0;
}
