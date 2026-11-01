//
// Created by Max Tyson on 31/10/2026.
//

#ifndef LIBNET_ADDRESS_MAC_H
#define LIBNET_ADDRESS_MAC_H

#include <cstdint>

namespace LibNet::address {

    constexpr uint64_t BROADCAST_MAC = 0xFFFFFFFFFFFF;

    class MediaAccessControlAddress {

        private:

            uint64_t m_address;

        public:
            MediaAccessControlAddress(uint64_t address);
            MediaAccessControlAddress(uint8_t digit1, uint8_t digit2, uint8_t digit3, uint8_t digit4, uint8_t digit5, uint8_t digit6);
            ~MediaAccessControlAddress();

            uint64_t address();

    };

    typedef MediaAccessControlAddress mac_t;


}

#endif //LIBNET_ADDRESS_MAC_H
