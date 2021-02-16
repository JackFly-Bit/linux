#include <cstdio>
#include <iostream>

#include "httplib.h"

void http_callback(const httplib::Request& req, httplib::Response& resp)
{
    (void)req;
    std::string body = "<html><p1>linux too easy</p1><html>";
    resp.set_content(body.c_str(), body.size(), "text/html");
}

int main()
{
    httplib::Server svr;
    svr.Get("/aaa", http_callback);

    svr.listen("0.0.0.0", 17878);
    return 0;
}
