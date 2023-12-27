#include "game_functions.h"


void equipment()
{
    bool  keeppocketopen = true;
    while (keeppocketopen)
    {
        std::cout << "HP: " << HP << "\t\t\tCoin: " << coin << std::endl;
        int count = 0;
        while (count < 1)
        {
            if (count % 5 == 0)
                std::cout << std::endl;

            if (bag[0][0])
            {
                std::cout << "Sword";
                count++;
            }
        }
        std::cout << "\n\n";
        std::cout << "0. Confirm\n1. Ehh...\nClose pocket? ";
        int option;
        std::cin >> option;
        std::cout << "\e[1;1H\e[2J";
        if (option == 0)
            break;
    }
}
