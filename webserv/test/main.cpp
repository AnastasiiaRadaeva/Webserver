#include "../Request.hpp"
#include <iostream>

int main()
{
    Request req;
    std::string str_1("G");
    std::string str_2("E");
    std::string str_3("T");
    std::string str_4(" /");
    std::string str_5(" HTTP/1.1\r");
    std::string str_6("\nhghjghjghjg");

    size_t      status;

    status = req.processRequest(str_1);
    status = req.processRequest(str_2);
    status = req.processRequest(str_3);
    status = req.processRequest(str_4);
    status = req.processRequest(str_5);
    status = req.processRequest(str_6);
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