#include "game_functions.h"

void bear(int &HP)
{
    int bearHP = 75;
    while (bearHP > 0)
    {
        std::cout << "HP: " << HP << "\t\t\tBear HP: " << bearHP << std::endl;
        sleep(1);
        std::cout << "0. Open bag\n1. Attack\nLet's ";
        int option;
        std::cin >> option;
        std::cout << "\e[1;1H\e[2J";
        std::cout << "HP: " << HP << "\t\t\tBear HP: " << bearHP << std::endl;
        sleep(1);

        if (option == 1)
        {
            int temp = rand() % 20;
            if (temp == 0)
                std::cout << "You stab the bear but it blocks your sword" << std::endl;
            else
            {
                temp = rand() % 5 + 8;
                std::cout << "You slash the bear with " << temp << " damage" << std::endl;
                bearHP -= temp;
                if (bearHP <= 0)
                    break;
            }
            sleep(5);
            std::cout << "\e[1;1H\e[2J";
            std::cout << "HP: " << HP << "\t\t\tBear HP: " << bearHP << std::endl;
            sleep(1);

            temp = rand() % 50;
            if (temp < 9)
                std::cout << "You dodge when the bear runs toward you" << std::endl;
            else
            {
                temp = rand() % 3 + 10;
                std::cout << "The bear jumps up and lands behind you to bite" << std::endl;
                sleep(2);
                std::cout << "-" << temp << " HP" << std::endl;
                HP -= temp;
                if (HP <= 0)
                {
                    sleep(2);
                    HP = 0;
                    break;
                }
                temp = rand() % 5;
                if (temp < 2)
                {
                    sleep(2);
                    std::cout << "That was a deep bite" << std::endl;
                    sleep(2);
                    std::cout << "The wound starts bleeding" << std::endl;
                    sleep(2);
                    std::cout << "-5 HP" << std::endl;
                    HP -= 5;
                    if (HP <= 0)
                    {
                        sleep(2);
                        HP = 0;
                        break;
                    }
                    temp = rand() % 4;
                    if (temp < 3)
                    {
                        sleep(2);
                        std::cout << "It keeps bleeding" << std::endl;
                        sleep(2);
                        std::cout << "-5 HP" << std::endl;
                        HP -= 5;
                        if (HP <= 0)
                        {
                            sleep(2);
                            HP = 0;
                            break;
                        }
                    }
                }
            }
            sleep(5);
            std::cout << "\e[1;1H\e[2J";
        }
        if (option == 0)
        {
            std::cout << "\e[1;1H\e[2J";
            openbag(bearHP);
        }
    }
    if (bearHP <= 0)
    {
        sleep(5);
        std::cout << "\e[1;1H\e[2J";
        std::cout << "HP: " << HP << std::endl;
        sleep(1);
        std::cout << "You finally defeat that bear" << std::endl;
        sleep(2);
        int temp = rand() % 3 + 13;
        std::cout << "You got" << std::endl;
        sleep(2);
        std::cout << "+" << temp << " coins" << std::endl;
        sleep(2);
        coin += temp;
        temp = rand() % 2 + 3;
        std::cout << "You stab the bear's dead body for its meat" << std::endl;
        std::cout << "+" << temp << " raw meat" << std::endl;
        bag[1][5] += temp;
    }
}
