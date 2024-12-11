#include "game.hpp"
#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

void display_board(const std::array<char, 9>& board)
{
    for (size_t i = 0; i < board.size(); ++i)
    {
        std::cout << " | " << board[i];
        if ((i + 1) % 3 == 0)
        {
            std::cout << " |" << std::endl;
        }
    }
}

bool check_winner(const std::array<char, 9>& board, char symbol)
{
    for (int i = 0; i < 9; i += 3)
    {
        if (board[i] == symbol && board[i + 1] == symbol && board[i + 2] == symbol)
        {
            return true;
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        if (board[i] == symbol && board[i + 3] == symbol && board[i + 6] == symbol)
        {
            return true;
        }
    }

    if ((board[0] == symbol && board[4] == symbol && board[8] == symbol) ||
        (board[2] == symbol && board[4] == symbol && board[6] == symbol))
    {
        return true;
    }

    return false;
}

void play_game(Player& player1, Player& player2, bool vs_ai)
{
    std::array<char, 9> board{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    Player* current_player = &player1;
    int turns = 0;

    std::srand(std::time(nullptr));

    while (turns < 9)
    {
        display_board(board);

        int position;
        if (vs_ai && current_player == &player2)
        {
            do
            {
                position = std::rand() % 9;
            } while (board[position] != ' ');

            std::cout << "L'IA joue en position " << position + 1 << std::endl;
        }
        else
        {
            do
            {
                std::cout << current_player->name << ", entrez une position (1-9) : ";
                std::cin >> position;
                --position; 
            } while (position < 0 || position >= 9 || board[position] != ' ');
        }

        board[position] = current_player->symbole;

        if (check_winner(board, current_player->symbole))
        {
            display_board(board);
            std::cout << current_player->name << " win !" << std::endl;
            return;
        }

        current_player = (current_player == &player1) ? &player2 : &player1;
        ++turns;
    }

    display_board(board);
    std::cout << "Match nul !" << std::endl;
}

