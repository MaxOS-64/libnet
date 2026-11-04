//
// Created by Max Tyson on 02/11/2026.
//

#ifndef LIBNET_PROTOCOL_TRANSPORT_UDP_H
#define LIBNET_PROTOCOL_TRANSPORT_UDP_H

#include <cstdint>

namespace LibNet::protocol::transport {


    /**
     * @struct UDPHeader
     * @brief The header of a UDP packet
     *
     * @typedef udp_header_t
     * @brief Alias for UDPHeader struct
     */
    typedef struct PACKED UDPHeader {

        uint16_t source_port;            ///< The port of the sender
        uint16_t destination_port;       ///< The port of the receiver
        uint16_t length;                ///< The length of the UDP header and data
        uint16_t checksum;              ///< The checksum of the header and data

    } udp_header_t;


}


#endif //LIBNET_PROTOCOL_TRANSPORT_UDP_H
