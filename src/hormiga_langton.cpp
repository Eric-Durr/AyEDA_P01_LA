#include <iostream>
#include <string>
#include "../include/entorno.h"

int main(int argc, char *argv[])
{
    if (argc < 4 || argc > 7 || argc == 5)
    {
        std::cout << "ERROR: wrong number of arguments\n"
                     "\tUSAGE: ./hormiga_langton <columns> <rows> <steps> [ant_i] [ant_j] [ant_direction]\n";
        return 1;
    }

    if (argc == 4)
    {
        int columns_given = std::stoi(argv[1]);
        int rows_given = std::stoi(argv[2]);
        int steps_given = std::stoi(argv[3]);

        LangtonEnvironment default_env(rows_given, columns_given);
        std::cout << "Environment preview:\n\n"
                  << "Steps to take: " << steps_given << "\n"
                  << "Columns of the grid: " << columns_given << "\n"
                  << "Rows of the grid: " << rows_given << "\n"
                  << "Environment at start: \n\n"
                  << default_env << "\n\n";

        for (int i = 0; i < steps_given; i++)
        {
            default_env.step(1);
            std::cout << "\n--- paso " << i + 1 << " ---\n"
                      << default_env;
        }
    }

    if (argc == 6)
    {
        int columns_given = std::stoi(argv[1]);
        int rows_given = std::stoi(argv[2]);
        int steps_given = std::stoi(argv[3]);
        int ant_i_pos = std::stoi(argv[4]);
        int ant_j_pos = std::stoi(argv[5]);
        LangtonEnvironment anted_env(rows_given, columns_given, ant_i_pos, ant_j_pos);
        std::cout << "Environment preview:\n\n"
                  << "Steps to take: " << steps_given << "\n"
                  << "Columns of the grid: " << columns_given << "\n"
                  << "Rows of the grid: " << rows_given << "\n"
                  << "Environment at start: \n\n"
                  << anted_env << "\n\n";

        for (int i = 0; i < steps_given; i++)
        {
            anted_env.step(1);
            std::cout << "\n--- paso " << i + 1 << " ---\n"
                      << anted_env;
        }
    }

    if (argc == 7)
    {
        int columns_given = std::stoi(argv[1]);
        int rows_given = std::stoi(argv[2]);
        int steps_given = std::stoi(argv[3]);
        int ant_i_pos = std::stoi(argv[4]);
        int ant_j_pos = std::stoi(argv[5]);
        direction direction_given;
        if (std::string{argv[6]} == "UP")
            direction_given = UP;
        if (std::string{argv[6]} == "RI")
            direction_given = RI;
        if (std::string{argv[6]} == "DO")
            direction_given = DO;
        if (std::string{argv[6]} == "LE")
            direction_given = LE;

        LangtonEnvironment anted_env(rows_given, columns_given, ant_i_pos, ant_j_pos, direction_given);
        std::cout << "Environment preview:\n\n"
                  << "Steps to take: " << steps_given << "\n"
                  << "Columns of the grid: " << columns_given << "\n"
                  << "Rows of the grid: " << rows_given << "\n"
                  << "Environment at start: \n\n"
                  << anted_env << "\n\n";

        for (int i = 0; i < steps_given; i++)
        {
            anted_env.step(1);
            std::cout << "\n--- paso " << i + 1 << " ---\n"
                      << anted_env;
        }
    }

    return 0;
}