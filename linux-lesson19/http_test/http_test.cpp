#include <iostream>
#include <cstdio>
#include <cstring>

#include "httplib.h"

int g_count = 0;

int main(int argc, char* argv[])
{
    if(argc != 3){
        printf("Using ./http_svr [port] [parm]\n");
        return -1;
    }

    uint16_t port = atoi(argv[1]);
    std::string pram = argv[2];

    httplib::Server svr;
    svr.Get("/", [pram](const httplib::Request& requ, httplib::Response& resp){
            (void)requ;
            char buf[1024] = {0};
            snprintf(buf, sizeof(buf) - 1, "<html><h1>i am server : %s, request count : %d<h1></html>", pram.c_str(), ++g_count);
            resp.set_content(buf, strlen(buf), "text/html");
            });

    svr.listen("0.0.0.0", port);
    return 0;
}
