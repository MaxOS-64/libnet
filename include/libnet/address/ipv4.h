//
// Created by Max Tyson on 01/11/2026.
//

#ifndef LIBNET_ADDRESS_IPV4_H
#define LIBNET_ADDRESS_IPV4_H

#include <cstdint>
#include <libnet/address/mac.h>
#include <libcommon/map.h>
#include <libcommon/string.h>

namespace LibNet::address {

    constexpr uint8_t IP_ADDRESS_BYTES = 6;

    class InternetProtocolAddressVersion4 {

        private:
            uint32_t m_raw_address = 0;

        public:
            InternetProtocolAddressVersion4(uint32_t address_raw_host);
            InternetProtocolAddressVersion4(MaxOS::string address);
            InternetProtocolAddressVersion4(uint8_t octet1, uint8_t octet2, uint8_t octet3, uint8_t octet4);

            MaxOS::string to_string();
            uint32_t raw_address();

            bool is_unspecified() const;

            bool operator == (const InternetProtocolAddressVersion4& source_ip) const;
            bool operator != (const InternetProtocolAddressVersion4& ipv4_address) const;


    };

    typedef InternetProtocolAddressVersion4 ipv4_address_t;

    class Subnet {

        private:
            ipv4_address_t m_networkd_address;
            uint8_t m_prefix_length;

        public:
            Subnet(MaxOS::string subnet);
            Subnet(ipv4_address_t networkd_addrres, uint8_t prefix_length);

            uint8_t prefix_length();
            ipv4_address_t address();

            bool contains(ipv4_address_t address);

    };

    typedef Subnet subnet_t;

    /**
     * @class IPV4AddressResolver
     * @brief Resolves IP addresses to MAC addresses
     */
    class IPV4AddressResolver {

        protected:
            MaxOS::common::Map<ipv4_address_t, mac_t> m_address_cache;

            virtual void query_address(ipv4_address_t address);

        public:
            explicit IPV4AddressResolver();
            ~IPV4AddressResolver();

            mac_t resolve(ipv4_address_t address);
            void store(ipv4_address_t address, mac_t mac);
    };


}

#endif //LIBNET_ADDRESS_IPV4_H
