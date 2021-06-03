/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:53:45 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/06/03 18:06:25 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Request.hpp"

Request::Request() : _request_line(std::vector<std::string>()),_headers(std::map<std::string, std::string>()), _body(std::string()), _status(WAITING), _status_of_parts(std::vector<size_t>(3, WAITING)) {}
Request::Request(Request const &copy) : _request_line(copy._request_line), _headers(copy._headers), _body(copy._body), _status(copy._status), _status_of_parts(copy._status_of_parts) {}
Request &Request::operator=(Request const &a)
{
    if (this != &a)
    {
        _request_line = a._request_line;
        _headers = a._headers;
        _body = a._body;
        _status = a._status;
        _status_of_parts = a._status_of_parts;
    }
    return (*this);
}
Request::~Request() {}

size_t  Request::processRequest(std::string &str)
{
    size_t  pos_begin = 0;
    size_t  pos_end = 0;
    std::string new_str;

    if (_status_of_parts[0] == WAITING)
    {
        if ((pos_end = str.find(END)) != str.npos) // разобраться, сколько тут раз это повторяется
            _status_of_parts[0] = OK;
        new_str = std::string(str, pos_begin, pos_end - pos_begin);
        filling_request_line(new_str);
        pos_begin = pos_end + 4;
    }
    if (_status_of_parts[1] == WAITING && _status_of_parts[0] == OK)
    {
        if ((pos_end = str.find(END, pos_begin)) != str.npos)
            _status_of_parts[1] = OK;
        new_str = std::string(str, pos_begin, pos_end - pos_begin);
        filling_headers(new_str);
        pos_begin = pos_end + 4;
    }
    if (_status_of_parts[2] == WAITING && _status_of_parts[0] == OK && _status_of_parts[1] == OK)
    {
        //в хедерах я должна понять, будет ли тело и поменять статус тела на нужный 
    }
    return(_status);
}

/******************/
/*     Getters    */
/******************/
std::vector<std::string> const              &Request::getRequestLine()  { return(_request_line); }
std::map<std::string, std::string> const    &Request::getHeaders()      { return(_headers); }
std::string const                           &Request::getBody()         { return(_body); }

/*************************/
/*     Filling struct    */
/*************************/
//сюда подаем строку до первых \r\n\r\n, при условии status - waiting
//если не их обнаружено, записыва  
void    Request::filling_request_line(std::string &str)
{

}

void    Request::filling_headers(std::string &str)
{

}

