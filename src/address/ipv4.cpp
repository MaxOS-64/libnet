//
// Created by Max Tyson on 06/11/2026.
//

#include <libnet/address/ipv4.h>

using namespace MaxOS;
using namespace LibNet;
using namespace LibNet::address;

InternetProtocolAddressVersion4::InternetProtocolAddressVersion4(uint32_t address_raw_host)
: m_raw_address(address_raw_host)
{
}

InternetProtocolAddressVersion4::InternetProtocolAddressVersion4(MaxOS::string address) {

	auto parts = address.split(".");
	ASSERT(parts.size() == 4, "Need 4 octets for a IP address");

	octets_to_raw(parts[0].to_uint64(), parts[1].to_uint64(), parts[2].to_uint64(), parts[3].to_uint64());
}

InternetProtocolAddressVersion4::InternetProtocolAddressVersion4(uint8_t octet0, uint8_t octet1, uint8_t octet2, uint8_t octet3) {

	octets_to_raw(octet0, octet1, octet2, octet3);
}

void InternetProtocolAddressVersion4::octets_to_raw(uint8_t octet0, uint8_t octet1, uint8_t octet2, uint8_t octet3) {

	m_raw_address = octet0;
	m_raw_address = (m_raw_address << 8) | octet1;
	m_raw_address = (m_raw_address << 8) | octet2;
	m_raw_address = (m_raw_address << 8) | octet3;

}

uint8_t InternetProtocolAddressVersion4::get_octect(uint8_t num) {
	ASSERT(num < 4, "IPv4 octet index out of range");

	return (m_raw_address >> ((3 - num) * 8)) & 0xFF;
}

string InternetProtocolAddressVersion4::to_string() {
	return string(get_octect(0)) + '.' + string(get_octect(1)) + '.' + string(get_octect(2)) + '.' + string(get_octect(3));
}

uint32_t InternetProtocolAddressVersion4::raw_address() {
	return m_raw_address;
}

bool InternetProtocolAddressVersion4::is_unspecified() const {
	return m_raw_address == 0;
}

bool InternetProtocolAddressVersion4::operator == (const InternetProtocolAddressVersion4 &source_ip) const {
	return m_raw_address == source_ip.m_raw_address;
}

bool InternetProtocolAddressVersion4::operator != (const InternetProtocolAddressVersion4 &source_ip) const {
	return m_raw_address != source_ip.m_raw_address;
}


Subnet::Subnet(string subnet)
: Subnet(parse(subnet))
{

}

Subnet::Subnet(ipv4_address_t network_address, uint8_t prefix_length)
: m_network_address(network_address),
  m_prefix_length(prefix_length)
{
}

Subnet Subnet::parse(string subnet) {

	// assumes 0.0.0.0/k
	auto parts = subnet.split("/");

	return {
		parts[0],
		(uint8_t)parts[1].to_uint64()
	};
}

uint8_t Subnet::prefix_length() {
	return m_prefix_length;
}

ipv4_address_t Subnet::address() {
	return m_network_address;
}

bool Subnet::contains(ipv4_address_t address) {

	auto mask = (uint32_t)(0xFFFFFFFFULL << (32 - m_prefix_length));
	return (m_network_address.raw_address() & mask) == (address.raw_address() & mask);
}

bool Subnet::operator==(const Subnet &other) const {
	return m_prefix_length == other.m_prefix_length && m_network_address == other.m_network_address;
}

IPV4AddressResolver::IPV4AddressResolver() = default;

IPV4AddressResolver::~IPV4AddressResolver() = default;

mac_t IPV4AddressResolver::query_address(ipv4_address_t address) {

	NOT_IMPLEMENTED;

}

mac_t IPV4AddressResolver::resolve(ipv4_address_t address) {

	// Check if cached
	auto it = m_address_cache.find(address);
	if (it != m_address_cache.end())
		return it->second;

	// Resolve the address
	mac_t mac = query_address(address);
	store(address, mac);

	return mac;

}

void IPV4AddressResolver::store(ipv4_address_t address, mac_t mac) {
	m_address_cache.push_back(address, mac);
}
