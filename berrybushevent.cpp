#include "game_functions.h"


void berrybushevent(int &eventcount)
{
    eventcount++;
    while (true)
    {
        std::cout << "HP: " << HP << std::endl;
        sleep(1);
        std::cout << "You are walking and berry bushes along the river catch your sight" << std::endl;
        sleep(1);
        std::cout << "0. Open bag\n1. Harvest some berries\n2. Ignore it\n3. Star at the bushes\nYou decide to ";
        int option;
        std::cin >> option;
        std::cout << "\e[1;1H\e[2J";
        std::cout << "HP: " << HP << std::endl;
        sleep(1);

        if (option == 1)
        {
            int temp = rand() % 5 + 3;
            std::cout << "You walk toward and pick some berries" << std::endl;
            sleep(2);
            std::cout << "+" << temp << " berries" << std::endl;
            bag[1][1] += temp;
            temp = rand() % 10;
            if (temp < 3)
            {
                sleep(1);
                std::cout << "Wait";
                sleep(1);
                std::cout << ".";
                sleep(1);
                std::cout << ".";
                sleep(1);
                std::cout << ".";
                sleep(1);
                std::cout << std::endl;
                std::cout << "You step on an ant hill when you are about to leave" << std::endl;
                sleep(2);
                std::cout << "It is your fault for being clumsy" << std::endl;
                sleep(2);
                std::cout << "Now they climb up and bite you" << std::endl;
                sleep(2);
                temp = rand() % 3 + 1;
                std::cout << "-" << temp << " HP";
                HP -= temp;
                if (HP < 0)
                    HP = 0;
            }
        }
        if (option == 2)
        {
            int temp = rand() % 10;
            if (temp > 2)
                std::cout << "Although how delicious these berries look like, you walk away..." << std::endl;
            else
            {
                std::cout << "You turn your head away and suddenly a snake jumps out from the bushes and attacks you" << std::endl;
                sleep(5);
                std::cout << "\e[1;1H\e[2J";
                snake(HP);
            }
        }
        if (option == 3)
        {
            int temp = rand() % 10;
            if (temp < 7)
            {
                std::cout << "You just pick a berry and leave" << std::endl;
                sleep(2);
                std::cout << "+1 berry" << std::endl;
                bag[1][1]++;
            }
            else
            {
                temp = rand() % 3 + 1;
                if (temp == 1)
                {
                    std::cout << "You notice something shiny through the bushes" << std::endl;
                    sleep(2);
                    std::cout << "It is a coin" << std::endl;
                    sleep(2);
                    std::cout << "+1 coin" << std::endl;
                    coin++;
                }
                else
                {
                    std::cout << "You notice something shiny through the bushes" << std::endl;
                    sleep(2);
                    std::cout << "They are coins" << std::endl;
                    sleep(2);
                    std::cout << "+" << temp << " coin";
                    coin += temp;
                }
            }
        }
        if (option == 0)
        {
            std::cout << "\e[1;1H\e[2J";
            int blockusegoods = 0;
            openbag(blockusegoods);
        }
        else
        {
            sleep(5);
            std::cout << "\e[1;1H\e[2J";
            break;
        }
    }
}
