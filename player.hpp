#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>

struct Player
{
    std::string name;
    char symbole;

    void create_player(char existing_symbol = '\0');
};

#endif
