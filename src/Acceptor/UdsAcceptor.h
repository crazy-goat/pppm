//
// Created by piotr on 27.11.17.
//

#ifndef SHEPHERD_UDSACCEPTOR_H
#define SHEPHERD_UDSACCEPTOR_H

#include <boost/asio/local/stream_protocol.hpp>
#include "Acceptor.h"
#include "../Config/ConfigLoader.h"

namespace crazygoat::shepherd {
    class UdsAcceptor : public Acceptor {
    public:
        UdsAcceptor(
            boost::asio::io_service &io_service,
            const std::shared_ptr<ConfigLoader> &config
        );
        void accept(boost::asio::generic::stream_protocol::socket &socket, AsyncAcceptor function) override;

    private:
        std::shared_ptr<boost::asio::local::stream_protocol::acceptor> acceptor;
    };
}
#endif //SHEPHERD_UDSACCEPTOR_H