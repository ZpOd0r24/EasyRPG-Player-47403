#ifndef EP_PLAYEROTHER_H
#define EP_PLAYEROTHER_H

#include <deque>
#include <memory>
#include <map>

struct Game_PlayerOther;
struct Sprite_Character;
struct NameTag;
struct BattleAnimation;

struct PlayerOther {
	std::deque<std::tuple<int8_t, int, int>> mvq; // queue of move commands
	std::unique_ptr<Game_PlayerOther> ch; // character
	std::unique_ptr<Sprite_Character> sprite;
	std::unique_ptr<NameTag> name_tag;
	std::unique_ptr<BattleAnimation> battle_animation; // battle animation

	// type => pos
	std::map<int8_t, std::tuple<int8_t, int16_t, int16_t>> previous_pos;

	// create a copy of this
	// the copied player has no name, no battle animation and no move commands
	// but it is visible, in other words this function modifies the
	// global drawable list
	//
	// the player must be put inside fadeout_players after creation
	// destroying the player outside fadeout_players is undefined behavior
	PlayerOther GetCopy();
};

#endif
