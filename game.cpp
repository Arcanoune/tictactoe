#include "game.hpp"
#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

void plateau(const std::array<char, 9> &board)
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

bool gagnant(const std::array<char, 9> &board, char symbol)
{
    for (int i = 0; i < 9; i += 3)
    {
        if (board[i] == symbol && board[i + 1] == symbol && board[i + 2] == symbol)
            return true;
    }

    for (int i = 0; i < 3; ++i)
    {
        if (board[i] == symbol && board[i + 3] == symbol && board[i + 6] == symbol)
            return true;
    }

    if ((board[0] == symbol && board[4] == symbol && board[8] == symbol) ||
        (board[2] == symbol && board[4] == symbol && board[6] == symbol))
        return true;

    return false;
}

int deux_alignes(const std::array<char, 9> &board, char symbol, char opponent_symbol)
{
    for (int i = 0; i < 9; i += 3)
    {
        if (board[i] == opponent_symbol && board[i + 1] == opponent_symbol && board[i + 2] != symbol && board[i + 2] != opponent_symbol)
            return i + 2;
        if (board[i] == opponent_symbol && board[i + 2] == opponent_symbol && board[i + 1] != symbol && board[i + 1] != opponent_symbol)
            return i + 1;
        if (board[i + 1] == opponent_symbol && board[i + 2] == opponent_symbol && board[i] != symbol && board[i] != opponent_symbol)
            return i;
    }

    for (int i = 0; i < 3; ++i)
    {
        if (board[i] == opponent_symbol && board[i + 3] == opponent_symbol && board[i + 6] != symbol && board[i + 6] != opponent_symbol)
            return i + 6;
        if (board[i] == opponent_symbol && board[i + 6] == opponent_symbol && board[i + 3] != symbol && board[i + 3] != opponent_symbol)
            return i + 3;
        if (board[i + 3] == opponent_symbol && board[i + 6] == opponent_symbol && board[i] != symbol && board[i] != opponent_symbol)
            return i;
    }

    if (board[0] == opponent_symbol && board[4] == opponent_symbol && board[8] != symbol && board[8] != opponent_symbol)
        return 8;
    if (board[0] == opponent_symbol && board[8] == opponent_symbol && board[4] != symbol && board[4] != opponent_symbol)
        return 4;
    if (board[4] == opponent_symbol && board[8] == opponent_symbol && board[0] != symbol && board[0] != opponent_symbol)
        return 0;

    if (board[2] == opponent_symbol && board[4] == opponent_symbol && board[6] != symbol && board[6] != opponent_symbol)
        return 6;
    if (board[2] == opponent_symbol && board[6] == opponent_symbol && board[4] != symbol && board[4] != opponent_symbol)
        return 4;
    if (board[4] == opponent_symbol && board[6] == opponent_symbol && board[2] != symbol && board[2] != opponent_symbol)
        return 2;

    return -1;
}

void jeu(Player &player1, Player &player2, bool vs_ai)
{
    std::array<char, 9> board{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    Player *current_player = &player1;
    int turns = 0;

    std::srand(std::time(nullptr));

    while (turns < 9)
    {
        plateau(board);

        int position;
        if (vs_ai && current_player == &player2)
        {
            position = deux_alignes(board, player2.symbole, player1.symbole);

            if (position == -1)
            {
                do
                {
                    position = std::rand() % 9;
                } while (board[position] == player1.symbole || board[position] == player2.symbole);
            }

            std::cout << "IA joue en " << position + 1 << std::endl;
        }

        else
        {
            do
            {
                std::cout << current_player->name << " entrez une position (1-9) : ";
                std::cin >> position;
                --position;

                if (position < 0 || position >= 9 || board[position] == player1.symbole || board[position] == player2.symbole)
                {
                    std::cout << "Case déjà prise, réessayez !" << std::endl;
                }
            } while (position < 0 || position >= 9 || board[position] == player1.symbole || board[position] == player2.symbole);
        }

        board[position] = current_player->symbole;

        if (gagnant(board, current_player->symbole))
        {
            plateau(board);
            std::cout << current_player->name << " gagne !" << std::endl;
            return;
        }

        current_player = (current_player == &player1) ? &player2 : &player1;
        ++turns;
    }

    plateau(board);
    std::cout << "Match nul !" << std::endl;
}