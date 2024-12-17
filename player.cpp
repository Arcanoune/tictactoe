#include <iostream>
#include <limits>
#include "player.hpp"

void Player::joueur(const char existing_symbol)
{
    std::cout << "Pseudo : ";
    std::cin >> name;

    do
    {
        std::cout << "Symbole (entre b et z) : ";
        std::cin >> symbole;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "nop plus court" << std::endl;
            symbole = '\0';
        }
        else if (symbole < 'b' || symbole > 'z') 
        {
            std::cout << "lettre de l'alphabet sauf a" << std::endl;
            symbole = '\0';
        }
        else if (symbole == existing_symbol) 
        {
            std::cout << "symbole pris" << std::endl;
            symbole = '\0';
        }
    } while (symbole == '\0');
}
