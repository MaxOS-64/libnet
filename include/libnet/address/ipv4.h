//
// Created by Max Tyson on 01/11/2026.
//

#ifndef LIBNET_ADDRESS_IPV4_H
#define LIBNET_ADDRESS_IPV4_H

#include <cstdint>
#include <libnet/address/mac.h>
#include <libcommon/map.h>
#include <libcommon/assert.h>
#include <libcommon/string.h>
#include <libcommon/macros.h>

namespace LibNet::address {

    constexpr uint8_t IP_ADDRESS_BYTES = 6;

    class InternetProtocolAddressVersion4 {

        private:
            uint32_t m_raw_address = 0;

			void octets_to_raw(uint8_t octet0, uint8_t octet1, uint8_t octet2, uint8_t octet3);
    		uint8_t get_octect(uint8_t num);

        public:
            InternetProtocolAddressVersion4(uint32_t address_raw_host);
            InternetProtocolAddressVersion4(MaxOS::string address);
            InternetProtocolAddressVersion4(uint8_t octet0, uint8_t octet1, uint8_t octet2, uint8_t octet3);

            MaxOS::string to_string();
            uint32_t raw_address();

            bool is_unspecified() const;

            bool operator == (const InternetProtocolAddressVersion4& source_ip) const;
            bool operator != (const InternetProtocolAddressVersion4& ipv4_address) const;

    };

    typedef InternetProtocolAddressVersion4 ipv4_address_t;

    class Subnet {

        private:
            ipv4_address_t m_network_address;
            uint8_t m_prefix_length;

    		Subnet parse(MaxOS::string subnet);

        public:
            Subnet(MaxOS::string subnet);
            Subnet(ipv4_address_t network_address, uint8_t prefix_length);

            uint8_t prefix_length();
            ipv4_address_t address();

            bool contains(ipv4_address_t address);

            bool operator == (const Subnet& other) const;
    };

    typedef Subnet subnet_t;

    /**
     * @class IPV4AddressResolver
     * @brief Resolves IP addresses to MAC addresses
     */
    class IPV4AddressResolver {

        protected:
            MaxOS::common::Map<ipv4_address_t, mac_t> m_address_cache;

            virtual mac_t query_address(ipv4_address_t address);

        public:
            explicit IPV4AddressResolver();
            ~IPV4AddressResolver();

            mac_t resolve(ipv4_address_t address);
            void store(ipv4_address_t address, mac_t mac);
    };


}

#endif //LIBNET_ADDRESS_IPV4_H
