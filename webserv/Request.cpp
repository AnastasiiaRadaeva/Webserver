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

Request::Request() : _buff(std::string()), _request_line(std::vector<std::string>()),_headers(std::map<std::string, std::string>()), _body(std::string()), _status(WAITING), _status_of_parts(std::vector<size_t>(3, WAITING))
{
}
Request::Request(Request const &copy) : _buff(copy._buff), _request_line(copy._request_line), _headers(copy._headers), _body(copy._body), _status(copy._status), _status_of_parts(copy._status_of_parts)
{
}
Request &Request::operator=(Request const &a)
{
    if (this != &a)
    {
        _buff = a._buff;
        _request_line = a._request_line;
        _headers = a._headers;
        _body = a._body;
        _status = a._status;
        _status_of_parts = a._status_of_parts;
    }
    return (*this);
}
Request::~Request()
{
}

size_t  Request::processRequest(std::string &str)
{
    size_t  pos_begin = 0;
    size_t  pos_end = 0;

    if (_status_of_parts[0] == WAITING)
    {
        pos_end = str.find(NEXT_STR);
        _buff = std::string(str, pos_begin, pos_end);
        if (pos_end != str.npos)
        {
            _status_of_parts[0] = OK;
            filling_request_line();
            pos_begin = pos_end + 2;
        }
    }
    // if (_status_of_parts[1] == WAITING && _status_of_parts[0] == OK)
    // {
    //     if ((pos_end = str.find(END, pos_begin)) != str.npos)
    //         _status_of_parts[1] = OK;
    //     new_str = std::string(str, pos_begin, pos_end - pos_begin);
    //     filling_headers(new_str);
    //     pos_begin = pos_end + 4;
    // }
    // if (_status_of_parts[2] == WAITING && _status_of_parts[0] == OK && _status_of_parts[1] == OK)
    // {
    //     //в хедерах я должна понять, будет ли тело и поменять статус тела на нужный 
    // }
    return(_status_of_parts[0]);
}

/******************/
/*     Getters    */
/******************/
std::string const                           &Request::getMethod()   { return(_request_line[0]); }
std::string const                           &Request::getURI()      { return(_request_line[1]); }
std::string const                           &Request::getVersion()  { return(_request_line[2]); }
std::map<std::string, std::string> const    &Request::getHeaders()  { return(_headers); }
std::string const                           &Request::getBody()     { return(_body); }

/*************************/
/*     Filling struct    */
/*************************/
void    Request::filling_request_line()
{
    size_t  pos_space = 0;
    size_t  pos_begin = 0;
    size_t  i = 0;
    while ((pos_space = _buff.find(' ', pos_begin)) != _buff.npos)
    {
        _request_line.push_back(std::string(_buff, pos_begin, pos_space - pos_begin));
        pos_begin = pos_space + 1;
        i++;
    }
    if (i == 2)
        _request_line.push_back(std::string(_buff, pos_begin, pos_space - pos_begin));
    else
    {
        _status_of_parts[0] = ERROR;
        _status = ERROR;
    }
}

void    Request::filling_headers()
{

}

