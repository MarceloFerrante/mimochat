////
//// Created by marcelo on 24/11/2021.
////
//
////
//// Copyright (c) 2016-2017 Vinnie Falco (vinnie dot falco at gmail dot com)
////
//// Distributed under the Boost Software License, Version 1.0. (See accompanying
//// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////
//// Official repository: https://github.com/boostorg/beast
////
//
////------------------------------------------------------------------------------
////
//// Example: WebSocket SSL client, synchronous
////
////------------------------------------------------------------------------------
//
//

#include "boost/asio.hpp"

//#include "cliente.h"
//
//#include "root_certificates.hpp"
//
//#include <boost/beast/core.hpp>
//#include <boost/beast/ssl.hpp>
//#include <boost/beast/websocket.hpp>
//#include <boost/beast/websocket/ssl.hpp>
//#include <boost/asio/connect.hpp>
//#include <boost/asio/ip/tcp.hpp>
//#include <boost/asio/ssl/stream.hpp>
//#include <cstdlib>
//#include <iostream>
//#include <string>
//
//namespace beast = boost::beast;         // from <boost/beast.hpp>
//namespace http = beast::http;           // from <boost/beast/http.hpp>
//namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
//namespace net = boost::asio;            // from <boost/asio.hpp>
//namespace ssl = boost::asio::ssl;       // from <boost/asio/ssl.hpp>
//using tcp = boost::asio::ip::tcp;       // from <boost/asio/endereco/tcp.hpp>
//
//#include "bancoDeDados/amigos.h"
//
//// Sends a WebSocket message and prints the response
//int enviaMensagem(BD::dados& d)
//{
//    try
//    {
//        std::string& host = d.endereco.ipv4;
//        auto const&  port = d.endereco.porta;
//        auto const&  text = d.texto.inicial;
//
//        // The io_context is required for all I/O
//        net::io_context ioc;
//
//        // The SSL context is required, and holds certificates
//        ssl::context ctx{ssl::context::tlsv12_client};
//
//        // This holds the root certificate used for verification
//        load_root_certificates(ctx);
//
//        // These objects perform our I/O
//        tcp::resolver resolver{ioc};
//        websocket::stream<beast::ssl_stream<tcp::socket>> ws{ioc, ctx};
//
//        // Look up the domain name
//        auto const results = resolver.resolve(host, port);
//
//        // Make the connection on the IP address we get from a lookup
//        auto ep = net::connect(get_lowest_layer(ws), results);
//
//        // Set SNI Hostname (many hosts need this to handshake successfully)
//        if(! SSL_set_tlsext_host_name(ws.next_layer().native_handle(), host.c_str()))
//            throw beast::system_error(
//                    beast::error_code(
//                            static_cast<int>(::ERR_get_error()),
//                            net::error::get_ssl_category()),
//                    "Failed to set SNI Hostname");
//
//        // Update the host_ string. This will provide the value of the
//        // Host HTTP header during the WebSocket handshake.
//        // See https://tools.ietf.org/html/rfc7230#section-5.4
//        host += ':' + std::to_string(ep.port());
//
//        // Perform the SSL handshake
//        ws.next_layer().handshake(ssl::stream_base::client);
//
//        // Set a decorator to change the User-Agent of the handshake
//        ws.set_option(websocket::stream_base::decorator(
//                [](websocket::request_type& req)
//                {
//                    req.set(http::field::user_agent,
//                            std::string(BOOST_BEAST_VERSION_STRING) +
//                            " websocket-client-coro");
//                }));
//
//        // Perform the websocket handshake
//        ws.handshake(host, "/");
//
//        // Send the message
//        ws.write(net::buffer(std::string(text)));
//
//        // This buffer will hold the incoming message
//        beast::flat_buffer buffer;
//
//        // Read a message into our buffer
//        ws.read(buffer);
//
//        // Close the WebSocket connection
//        ws.close(websocket::close_code::normal);
//
//        // If we get here then the connection is closed gracefully
//
//        // The make_printable() function helps print a ConstBufferSequence
//        std::cout << beast::make_printable(buffer.dados()) << std::endl;
//    }
//    catch(std::exception const& e)
//    {
//        std::cerr << "Error: " << e.what() << std::endl;
//        return EXIT_FAILURE;
//    }
//    return EXIT_SUCCESS;
//}
#include "cliente.h"

namespace BD{

    int pingAll(bancoDeDados &bd) {
// checa conexoes
        using namespace boost;
        asio::thread_pool pool(std::thread::hardware_concurrency());

        for (size_t i = 0; i < 10; ++i) { //TODO percorrer banco de dados

            asio::post(pool, [i]() {
                std::cout << "contato " << i << " " /*<< std::this_thread::get_id()*/ << std::endl;
            });
//        asio::post(pool, imprime) ;
        }

        pool.join();
        return 0;
    }
}