#ifndef EP_MULTIPLAYER_CHATUI_H
#define EP_MULTIPLAYER_CHATUI_H

#include <string>

class ChatUi {
public:
	static ChatUi& Instance();

	void Refresh(); // initializes chat or refreshes its theme
	void Update(); // called once per logical frame
	void SetFocus(bool focused);

	void GotMessage(int visibility, int room_id, std::string name,
			std::string message, std::string sys_name);

	void GotInfo(std::string msg);
	void SetStatusConnection(bool connected, bool connecting = false);
	void SetStatusRoom(unsigned int room_id);
};

inline ChatUi& CUI() { return ChatUi::Instance(); }

#endif
