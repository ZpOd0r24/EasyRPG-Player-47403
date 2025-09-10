#ifndef EP_SERVER_H
#define EP_SERVER_H

#include <memory>
#include <unordered_map>
#include <functional>
#include <queue>
#include <condition_variable>
#include <mutex>
#include "chat.h"

#ifndef SERVER
#  include "../game_config.h"
#endif

struct ServerConfig {
	bool no_heartbeats = false;
	std::string bind_address = "[::]:6500";
	std::string bind_address_2 = "";
	int max_users = 100;
};

class ServerListener;
class ServerSideClient;

class ServerMain {
	struct DataToSend;

	bool running = false;
	int client_id = 10;
	std::unordered_map<int, std::unique_ptr<ServerSideClient>> clients;

	std::unique_ptr<ServerListener> server_listener;
	std::unique_ptr<ServerListener> server_listener_2;

	std::queue<std::unique_ptr<DataToSend>> m_data_to_send_queue;
	std::condition_variable m_data_to_send_queue_cv;

	std::mutex m_mutex;

public:
	void Start(bool wait_thread = false);
	void Stop();

#ifndef SERVER
	void SetConfig(const Game_ConfigMultiplayer& _cfg);
#endif

	void ForEachClient(const std::function<void(ServerSideClient&)>& callback);
	void DeleteClient(const int id);
	void SendTo(const int from_client_id, const int to_client_id,
		const Chat::VisibilityType visibility, std::string_view data,
		const bool return_flag = false);
};

ServerMain& Server();

#endif
