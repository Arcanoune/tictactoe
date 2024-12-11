#ifndef GAME_HPP
#define GAME_HPP

#include <array>
#include "player.hpp"

void display_board(const std::array<char, 9>& board);

void play_game(Player& player1, Player& player2, bool vs_ai);

#endif