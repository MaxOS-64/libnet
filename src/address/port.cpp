//
// Created by 98max on 7/11/2026.
//

#include <libnet/address/port.h>

using namespace LibNet;
using namespace LibNet::address;

Port::Port(uint16_t port)
: m_port_number(port)
{
}

Port::~Port() = default;

uint16_t Port::raw_port() {
	return m_port_number;
}
