/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:50:08 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/06/03 16:08:35 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_HPP
# define REQUEST_HPP

# include <vector>
# include <map>
# include <string>

# define OK 0
# define WAIT_INFO 1
# define ERROR 2
//посмотреть, какого рода ошибки могут быть и как они отображаются

class Request
{
    public:
        std::vector<std::string>            request_line;
        std::map<std::string, std::string>  headers;
        std::string                         body;

        Request();
        Request(std::string &);
        Request(Request const &);
        Request &operator=(Request const &);
        ~Request();

        size_t  getStatus() const;

    private:
        size_t  _status;



        


};

#endif