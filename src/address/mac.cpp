//
// Created by Max Tyson on 31/10/2026.
//

#include <libnet/address/mac.h>

using namespace LibNet;
using namespace LibNet::address;

MediaAccessControlAddress::MediaAccessControlAddress(uint64_t address)
: m_address(address)
{
}

//
/**
 * @brief Create a Media Access Control Address
 *
 * @note if your mac address is e.g. 1c:6f:65:07:ad:1a (see output of ifconfig)
 * then you would call MediaAccessControlAddress(0x1c, 0x6f, 0x65, 0x07, 0xad, 0x1a)
 *
 * @param digit1 The first digit
 * @param digit2 The second digit
 * @param digit3 The third digit
 * @param digit4 The fourth digit
 * @param digit5 The fifth digit
 * @param digit6 The last digit
 * @return The MAC address
 */
MediaAccessControlAddress::MediaAccessControlAddress(uint8_t digit1, uint8_t digit2, uint8_t digit3, uint8_t digit4, uint8_t digit5, uint8_t digit6) {

    m_address = (uint64_t) digit6 << 40
              | (uint64_t) digit5 << 32
              | (uint64_t) digit4 << 24
              | (uint64_t) digit3 << 16
              | (uint64_t) digit2 << 8
              | (uint64_t) digit1;


}

MediaAccessControlAddress::~MediaAccessControlAddress() = default;

uint64_t MediaAccessControlAddress::address() {
    return m_address;
}
