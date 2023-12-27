#include "game_functions.h"


void bat(int &HP)
{
    int batHP = 23;
    while (batHP > 0)
    {
        std::cout << "HP: " << HP << "\t\t\tBat HP: " << batHP << std::endl;
        sleep(1);
        std::cout << "0. Open bag\n1. Attack\nLet's ";
        int option;
        std::cin >> option;
        std::cout << "\e[1;1H\e[2J";
        std::cout << "HP: " << HP << "\t\t\tBat HP: " << batHP << std::endl;
        sleep(1);

        if (option == 1)
        {
            int temp = rand() % 20;
            if (temp == 0)
                std::cout << "You slash the bat but it flies up" << std::endl;
            else
            {
                temp = rand() % 5 + 8;
                std::cout << "You stab the bat with " << temp << " damage" << std::endl;
                batHP -= temp;
                if (batHP <= 0)
                    break;
            }
            sleep(5);
            std::cout << "\e[1;1H\e[2J";
            std::cout << "HP: " << HP << "\t\t\tBat HP: " << batHP << std::endl;
            sleep(1);

            temp = rand() % 20;
            if (temp == 0)
                std::cout << "The bat flies downward to you and opens its mouth to bite but you block its mouth with your sword" << std::endl;
            else
            {
                temp = rand() % 2 + 2;
                std::cout << "The bat bites you" << std::endl;
                sleep(2);
                std::cout << "-" << temp << " HP" << std::endl;
                HP -= temp;
                if (HP <= 0)
                {
                    sleep(2);
                    HP = 0;
                    break;
                }
            }
            sleep(5);
            std::cout << "\e[1;1H\e[2J";
        }
        if (option == 0)
        {
            std::cout << "\e[1;1H\e[2J";
            openbag(batHP);
        }
    }
    if (batHP <= 0)
    {
        sleep(5);
        std::cout << "\e[1;1H\e[2J";
        std::cout << "HP: " << HP << std::endl;
        sleep(1);
        std::cout << "You kill the bat" << std::endl;
        sleep(2);
        int temp = rand() % 2 + 2;
        std::cout << "You got" << std::endl;
        sleep(2);
        std::cout << "+" << temp << " coins" << std::endl;
        sleep(2);
        coin += temp;
        std::cout << "An apple and a berry fall off the bat body" << std::endl;
        sleep(2);
        std::cout << "+1 apple" << std::endl;
        bag[1][0]++;
        std::cout << "+1 berry" << std::endl;
        bag[1][1]++;
        temp = rand() % 10;
        if (temp < 4)
        {
            sleep(2);
            std::cout << "A bat hears its friend scream" << std::endl;
            sleep(2);
            std::cout << "it comes to revenge" << std::endl;
            sleep(5);
            std::cout << "\e[1;1H\e[2J";
            bat(HP);
        }
    }
}
