#include "../Request.hpp"
#include <iostream>

int main()
{
    Request req;
    std::string str("GET / HTTP/1.1\r\n");
    size_t      status;

    status = req.processRequest(str);
    if (status == OK)
    {
        std::cout << "OK" << std::endl;
        std::cout << req.getMethod() << std::endl;
        std::cout << req.getURI() << std::endl;
        std::cout << req.getVersion() << std::endl;
    }
    else
        std::cout << (status == ERROR ? "ERROR" : "WAITING") << std::endl;
    return (0);
}