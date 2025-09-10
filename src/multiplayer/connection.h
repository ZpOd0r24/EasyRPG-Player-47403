#ifndef EP_MULTIPLAYER_CONNECTION_H
#define EP_MULTIPLAYER_CONNECTION_H

#include <queue>
#include <map>
#include <functional>
#include <type_traits>

#include "packet.h"

namespace Multiplayer {

class Connection {
public:
	static void ParseAddress(std::string address, std::string& host, uint16_t& port);

	Connection() {}
	Connection(const Connection&) = delete;
	Connection(Connection&&) = default;
	Connection& operator=(const Connection&) = delete;
	Connection& operator=(Connection&&) = default;

	virtual ~Connection() = default;

	void SendPacket(const Packet& p);

	template<typename M, typename = std::enable_if_t<std::conjunction_v<
		std::is_convertible<M, Packet>
	>>>
	void RegisterHandler(std::function<void (M&)> h) {
		handlers.emplace(M::packet_type, [this, h](std::istream& is) {
			M pack;
			pack.FromStream(is, crypt_key);
			std::invoke(h, pack);
		});
	}

	enum class SystemMessage {
		OPEN,
		CLOSE,
		TERMINATED, // client connection has terminated
		EOD, // end of data to flush packets
		_PLACEHOLDER,
	};
	using SystemMessageHandler = std::function<void (Connection&)>;
	void RegisterSystemHandler(SystemMessage m, SystemMessageHandler h);

	bool Encrypted();
	std::string GetCryptKey();
	void SetCryptKey(std::string key);

protected:
	virtual void Open() = 0;
	virtual void Close() = 0;
	virtual void Send(std::string_view data) = 0;

	void Dispatch(const std::string_view data);
	void DispatchSystem(SystemMessage m);

private:
	std::map<uint8_t, std::function<void (std::istream&)>> handlers;
	SystemMessageHandler sys_handlers[static_cast<size_t>(SystemMessage::_PLACEHOLDER)];

	std::string crypt_key;
};

inline bool Connection::Encrypted() {
	return !crypt_key.empty();
}

inline std::string Connection::GetCryptKey() {
	return crypt_key;
}

inline void Connection::SetCryptKey(std::string key) {
	crypt_key = std::move(key);
}

} // end of namespace

#endif
