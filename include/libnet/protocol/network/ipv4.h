//
// Created by Max Tyson on 02/11/2026.
//

#ifndef LIBNET_PROTOCOL_NETWORK_IPV4_H
#define LIBNET_PROTOCOL_NETWORK_IPV4_H


#include <cstdint>
#include <libcommon/macros.h>

namespace LibNet::protocol::network {


    /**
     * @struct IPV4Header
     * @brief The header of an IPv4 packet
     *
     * @typedef ipv4_header_t
     * @brief Alias for IPV4Header struct
     */
    typedef struct PACKED IPV4Header {

        uint8_t header_length : 4;        ///< The length of the header in 32-bit words (min 5, max 15)
        uint8_t version : 4;             ///< The version of the IP protocol (4 for IPv4)
        uint8_t type_of_service;          ///< The type of service (low delay, high throughput, high reliability, etc. @todo: enum
        uint16_t total_length;           ///< The total length of the IP packet (header + data) in bytes

        uint16_t identifier;            ///< Unique identifier for the group of fragments of a single IP packet
        uint16_t flags_and_offset;        ///< Flags (3 bits) and Fragment Offset (13 bits) @todo: bitfield struct?

        uint8_t time_to_live;             ///< The maximum hops between devices before the packet is discarded
        uint8_t protocol;               ///< The protocol of the payload (TCP, UDP, ICMP, etc. @todo: enum
        uint16_t checksum;              ///< The checksum of the header

        uint32_t source_ip;              ///< The IP of the sender
        uint32_t destination_ip;         ///< The IP of the receiver

    } ipv4_header_t;

    typedef enum InternetProtocolType {

        ICMP = 0,
        TCP = 6,
        UDP = 17,

    } ip_protocol_t;

}


#endif //LIBNET_PROTOCOL_NETWORK_IPV4_H
