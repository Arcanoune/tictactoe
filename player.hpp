#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>

struct Player
{
    std::string name;
    char symbole;

    void joueur(char existing_symbol = '\0');
};

#endif
