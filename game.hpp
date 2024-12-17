#ifndef GAME_HPP
#define GAME_HPP

#include <array>
#include "player.hpp"

void plateau(const std::array<char, 9>& board);

void jeu(Player& player1, Player& player2, bool vs_ai);

#endif