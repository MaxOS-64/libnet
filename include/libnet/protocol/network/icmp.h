//
// Created by Max Tyson on 02/11/2026.
//

#ifndef MAXOS_ICMP_H
#define MAXOS_ICMP_H

#include <libcommon/macros.h>

namespace LibNet::protocol::network {

    /**
     * @struct ICMPHeader
     * @brief The header of an ICMP packet
     *
     * @typedef icmp_header_t
     * @brief Alias for ICMPHeader struct
     */
    typedef struct PACKED ICMPHeader {

        uint8_t type;           ///< The type of ICMP message
        uint8_t code;           ///< The code of the ICMP message

        uint16_t checksum;      ///< checksum to verify integrity
        uint32_t data;          ///< Payload data (Varies by type and code)

    } icmp_header_t;

    enum class ICMPType {

        ECHO_REPLY,
        ECHO_REQUEST = 8,

    };


}

#endif //MAXOS_ICMP_H
