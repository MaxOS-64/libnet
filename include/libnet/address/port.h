//
// Created by Max Tyson on 02/11/2026.
//

#ifndef LIBNET_ADDRESS_PORT_H
#define LIBNET_ADDRESS_PORT_H

namespace LibNet::address {

    class Port {

        private:
            uint16_t m_port_number = 0;

        public:
            Port(uint16_t port);
            ~Port();

            uint16_t raw_port();

    };

    typedef Port port_t;


}

#endif //LIBNET_ADDRESS_PORT_H
