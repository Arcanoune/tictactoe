#include <iostream>
#include <limits>
#include "player.hpp"

void Player::create_player(const char existing_symbol)
{
    std::cout << "Pseudo : ";
    std::cin >> name;

    do
    {
        std::cout << "Symbole : ";
        std::cin >> symbole;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Plus court chef" << std::endl;
            symbole = '\0';
        }
        else if (symbole == existing_symbol)
        {
            std::cout << "Déjà pris" << std::endl;
            symbole = '\0';
        }
    } while (symbole == '\0');
}