//
// Created by Max Tyson on 02/11/2026.
//

#ifndef LIBNET_PROTOCOL_TRANSPORT_TCP_H
#define LIBNET_PROTOCOL_TRANSPORT_TCP_H

#include <cstdint>

namespace LibNet::protocol::transport {

    /**
	 * @enum TCPSocketState
	 * @brief The state of a TCP socket
	 */
	enum class TCPSocketState {
		CLOSED,
		LISTEN,
		SYN_SENT,
		SYN_RECEIVED,

		ESTABLISHED,

		FIN_WAIT1,
		FIN_WAIT2,
		CLOSING,
		TIME_WAIT,

		CLOSE_WAIT,
		LAST_ACK
	};

	/**
	 * @enum TCPFlag
	 * @brief The flags in a TCP header
	 */
	enum class TCPFlag {
		FIN = 1,
		SYN = 2,
		RST = 4,
		PSH = 8,
		ACK = 16,
		URG = 32,
		ECE = 64,
		CWR = 128,
		NS = 256
	};

	/**
	 * @struct TCPHeader
	 * @brief The header of a TCP packet
	 *
	 * @typedef tcp_header_t
	 * @brief Alias for TCPHeader struct
	 */
	typedef struct PACKED TCPHeader {

		uint16_t src_port;                   ///< The port of the sender
		uint16_t dst_port;                   ///< The port of the receiver
		uint32_t sequence_number;            ///< Where this packet's data fits in the overall order of the data stream
		uint32_t acknowledgement_number;     ///< The next expected sequence number from the sender (used by the receiver to request the next data)

		uint8_t reserved : 4;                ///< Unused, must be 0
		uint8_t header_size_32w : 4;            ///< The size of the header in 32-bit words
		uint8_t flags;                      ///< The flags of the TCP packet (see TCPFlag enum)

		uint16_t window_size;                ///< How many bytes the sender is willing to receive
		uint16_t checksum;                  ///< The checksum of the header
		uint16_t urgent_ptr;                 ///< Where in the data the urgent data *ends* (if the URG flag is set)

		uint32_t options;                   ///< The options for the TCP packet (MSS, Window Scale, SACK Permitted) @todo: make this a struct

	} tcp_header_t;

	/**
	 * @struct TCPPseudoHeader
	 * @brief The pseudo header used for TCP checksum calculation
	 *
	 * @details The pseudo header is used to calculate the checksum of the TCP header. It is a copy of the IP
	 * header, but with the protocol field set to 6 (TCP) and the length field set to the length of the TCP header.
	 * As ip identifies packets, it uses this in the checksum to ensure they arent corrupted
	 *
	 * @typedef tcp_pseudo_header_t
	 * @brief Alias for TCPPseudoHeader struct
	 */
	typedef struct PACKED TCPPseudoHeader {

		uint32_t src_ip;         ///< The IP address of the sender
		uint32_t dst_ip;         ///< The IP address of the receiver
		uint8_t zero;
		uint8_t protocol;      ///< The protocol (set to 6 for TCP)
		uint16_t total_length;   ///< The total length of the TCP header and data

	} tcp_pseudo_header_t;

    constexpr size_t MIN_TCP_PACKET_LEN = 13;


}

#endif //LIBNET_PROTOCOL_TRANSPORT_TCP_H
