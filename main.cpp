#include <iostream>
#include "player.hpp"
#include "game.hpp"

int main()
{
    int mode;
    do
    {
        std::cout << "Bienvenue dans le jeu du TicTacToe\n";
        std::cout << "Veuillez choisir un mode de jeu :\n";
        std::cout << "1. Deux joueurs\n";
        std::cout << "2. Contre une IA\n";
        std::cin >> mode;
    } while (mode != 1 && mode != 2);

    Player player1;
    player1.create_player();

    Player player2;
    if (mode == 1)
    {
        player2.create_player(player1.symbole);
    }
    else
    {
        player2.name = "IA";
        player2.symbole = 'O';
    }

    play_game(player1, player2, mode == 2);

    return 0;
}