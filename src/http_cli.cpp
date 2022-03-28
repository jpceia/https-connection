/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:43:02 by jpceia            #+#    #+#             */
/*   Updated: 2022/03/27 02:57:51 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>
#include "TCP/Socket.hpp"
#include "HTTP/Connection.hpp"
#include "HTTP/Request.hpp"
#include "HTTP/Response.hpp"

#include <sstream>
#include <iostream>

int main(int argc, char *argv[])
{
    // Now we're taking an ipaddress and a port number as arguments to our program
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <domain> <port>" << std::endl;
        return 1;
    }

    std::string host(argv[1]);
    int port;
    {
        std::stringstream ss(argv[2]);
        ss >> port;
    }
    
    TcpSocket client(host, port);
    HttpConnection conn = client.connect();
    // Send a GET request to the server
    conn.sendRequest(HttpRequest());

    HttpResponse response = conn.recvResponse();

    std::cout << response << std::endl;
    
    client.close();

    return 0;
}