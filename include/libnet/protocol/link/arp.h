//
// Created by Max Tyson on 01/11/2026.
//

#ifndef LIBNET_PROTOCOL_LINK_ARP_H
#define LIBNET_PROTOCOL_LINK_ARP_H

#include <cstdint>
#include <libcommon/macros.h>

namespace LibNet::protocol::link {

    typedef enum class HardwareType {

        ETHERNET = 1

    } arp_hardware_type_t;

    typedef enum class ProtocolType {

        IPV4 = 0x0800

    } arp_protocol_type_t;


    typedef enum class ARPCommand {

        REQUEST = 1,
        REPLY

    } arp_command_t;

    /**
     * @struct ARPMessage
     * @brief An ARP message
     *
     * @typedef arp_message_t
     * @brief Alias for ARPMessage struct
     *
     * @todo use @see s
     */
    typedef struct PACKED ARPMessage {

        uint16_t hardware_type;             ///< The type of device that sent the ARP message (1 = Ethernet)
        uint16_t protocol;                  ///< The protocol being used (0x0800 = IPv4)
        uint8_t hardware_address_size;      ///< The size of the hardware address (6 for MAC)
        uint8_t protocol_address_size;      ///< The size of the protocol address (4 for IPv4)

        uint16_t command;                   ///< The ARP command

        uint64_t src_mac : 48;               ///< The MAC address of the sender
        uint32_t src_ip;                    ///< The IP address of the sender
        uint64_t dest_mac : 48;             ///< The MAC address of the target
        uint32_t dest_ip;                   ///< The IP address of the target


    } arp_message_t;

}

#endif //LIBNET_PROTOCOL_LINK_ARP_H
