/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:50:08 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/06/03 18:03:28 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_HPP
# define REQUEST_HPP

# include <vector>
# include <map>
# include <string>
# include <iostream>

# define OK 0
# define WAITING 1
# define ERROR 2
# define END "\r\n\r\n"
# define NEXT_STR "\r\n"

//посмотреть, какого рода ошибки могут быть и как они отображаются

class Request
{
    public:
        Request();
        Request(Request const &);
        Request &operator=(Request const &);
        ~Request();

        std::string const                           &getMethod();
        std::string const                           &getURI();
        std::string const                           &getVersion();
        std::map<std::string, std::string> const    &getHeaders();
        std::string const                           &getBody();

        size_t  processRequest(std::string &);

    private:
        std::string                         _buff;
        std::vector<std::string>            _request_line;
        std::map<std::string, std::string>  _headers;
        std::string                         _body;
        size_t                              _status;
        std::vector<size_t>                 _status_of_parts;

        void    filling_request_line();
        void    filling_headers();

        

};

#endif