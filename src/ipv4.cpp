//
// Created by Max Tyson on 02/11/2026.
//

#include <libnet/address/ipv4.h>
#include <libkpi/processes/thread.h>

using namespace LibNet;
using namespace LibNet::address;
using namespace MaxOS;
using namespace MaxOS::common;
using namespace MaxOS::KPI::processes;



/**
 * @brief Get the MAC address from an IP via ARP.
 *
 * @param address The IP address to get the MAC address from.
 * @return The MAC address of the IP address.
 *
 * @todo Should have a timeout in case the address cannot be resolved and avoid infinite loops
 * @todo Also, should yield the user code
 */
mac_t IPV4AddressResolver::resolve(ipv4_address_t address) {

    volatile auto cache_iterator = m_address_cache.find(address);

    // Mac address not known so wait to find it
    if (m_address_cache.end() == cache_iterator)
        query_address(address);


    // Wait for the
    while (cache_iterator == m_address_cache.end()) {
        cache_iterator = m_address_cache.find(address);
        yield();
    }

    return cache_iterator->second;
}

/**
 * @brief store a mapping of an IP address to a MAC address.
 *
 * @param address The IP address.
 * @param mac The MAC address.
 */
void IPV4AddressResolver::store(ipv4_address_t address, mac_t mac) {
    m_address_cache.insert(address, mac);
}
