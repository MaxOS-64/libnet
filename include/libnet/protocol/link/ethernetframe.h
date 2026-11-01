//
// Created by Max Tyson on 01/11/2026.
//

#ifndef LIBNET_PROTOCOL_LINK_ETHERNETFRAME_H
#define LIBNET_PROTOCOL_LINK_ETHERNETFRAME_H

#include <cstdint>


namespace LibNet::protocol::link {

    typedef enum class EthernetFrameType {

    } ethernet_frame_type_t;

    /**
     * @struct EthernetFrameHeader
     * @brief Structure the raw data. This is the header of an Ethernet Frame
     *
     * @typedef ethernet_frame_header_t
     * @brief Alias for EthernetFrameHeader struct
     */
    typedef struct PACKED EthernetFrameHeader {

        uint64_t destination_mac : 48;     ///< The mac address of the target (Big Endian)
        uint64_t source_mac : 48;          ///< The mac address of the sender (Big Endian)

        uint16_t type;                  ///< The type (Big Endian) 0x0800 = IPv4, 0x0806 = ARP, 0x86DD = IPv6

    } ethernet_frame_header_t;

    /**
     * @struct EthernetFrameFooter
     * @brief Structure the raw data. This is the footer of an Ethernet Frame
     *
     * @typedef ethernet_frame_footer_t
     * @brief Alias for EthernetFrameFooter struct
     */
    typedef struct PACKED EthernetFrameFooter {

        uint32_t checksum;            ///< checksum of the payload

    } ethernet_frame_footer_t;



}

#endif //LIBNET_PROTOCOL_LINK_ETHERNETFRAME_H
