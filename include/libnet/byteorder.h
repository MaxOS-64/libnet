//
// Created by Max Tyson on 31/10/2026.
//

#ifndef LIBNET_BYTEORDER_H
#define LIBNET_BYTEORDER_H

#include <cstdint>

namespace LibNet {

    template<typename T> constexpr T byte_swap(T value);

    template<typename T> T host_to_network(T value);
    template<typename T> T network_to_host(T value);

    template<typename T> constexpr T byte_swap(T value) {

        static_assert(sizeof(T) == 1 || sizeof(T) == 2 || sizeof(T) == 4 || sizeof(T) == 8, "Unsupported size for byte order conversion");

        switch (sizeof(T)) {

            case 1:
                return value;

            case 2:
                return (T) __builtin_bswap16((uint16_t) value);

            case 4:
                return (T) __builtin_bswap32((uint32_t) value);

            case 8:
                return (T) __builtin_bswap64((uint64_t) value);

            default:
                return -1;

        }
    }


    template <typename T> T host_to_network(T value) {
        return byte_swap(value);
    }

    template <typename T> T network_to_host(T value) {
        return byte_swap(value);
    }


}

#endif //LIBNET_BYTEORDER_H
