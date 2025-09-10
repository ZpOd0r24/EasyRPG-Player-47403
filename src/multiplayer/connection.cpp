#include <sstream>
#include "connection.h"
#include "output_mt.h"
#include "util/hexdump.h"

using namespace Multiplayer;

void Connection::ParseAddress(std::string address, std::string& host, uint16_t& port) {
	size_t pos = 0;
	if (address.find("[") != std::string::npos) {
		address.erase(0, 1);
		pos = address.find("]:");
		if (pos == std::string::npos) {
			address.erase(address.size() - 1);
			host = address;
			return;
		}
		host = address.substr(0, pos);
		address.erase(0, pos + 2);
		port = atoi(address.c_str());
		return;
	}
	pos = address.find(":");
	if (pos == std::string::npos) {
		host = address;
		return;
	}
	host = address.substr(0, pos);
	address.erase(0, pos + 1);
	port = atoi(address.c_str());
}

void Connection::SendPacket(const Packet& p) {
	Send(p.ToBytes(crypt_key));
}

void Connection::Dispatch(const std::string_view data) {
	std::istringstream iss(std::string(data), std::ios_base::binary);
	while (!iss.eof()) {
		std::istringstream pkt_iss(DeSerializeString16(iss));
		ReadU16(pkt_iss); // skip unused bytes
		auto packet_type = ReadU8(pkt_iss);
		auto it = handlers.find(packet_type);
		if (it != handlers.end()) {
			std::invoke(it->second, pkt_iss);
		} else {
			break;
		}
		iss.peek(); // check eof
	}
}

void Connection::RegisterSystemHandler(SystemMessage m, SystemMessageHandler h) {
	sys_handlers[static_cast<size_t>(m)] = h;
}

void Connection::DispatchSystem(SystemMessage m) {
	auto f = sys_handlers[static_cast<size_t>(m)];
	if (f)
		std::invoke(f, *this);
}
