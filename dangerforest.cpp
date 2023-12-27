#include "game_functions.h"


void dangerforest(int &eventcount)
{
    eventcount++;
    while (true)
    {
        std::cout << "HP: " << HP << std::endl;
        sleep(1);
        std::cout << "You are walking through the forest and hear something is roaring" << std::endl;
        sleep(2);
        std::cout << "You wonder what was that" << std::endl;
        sleep(2);
        std::cout << "0. Open bag\n1. Go hide\n2. Leave the area\n3. Seek the sound\nYou decide to ";
        int option;
        std::cin >> option;
        std::cout << "\e[1;1H\e[2J";
        std::cout << "HP: " << HP << std::endl;
        sleep(1);

        if (option == 1)
        {
            std::cout << "You think hiding somewhere is better" << std::endl;
            sleep(2);
            std::cout << "You hide behind a tree surrounded by bushes" << std::endl;
            sleep(2);
            int temp = rand() % 10;
            if (temp == 0)
            {
                std::cout << "You hear something breathing behind you" << std::endl;
                sleep(2);
                std::cout << "It is a wolf" << std::endl;
                sleep(2);
                std::cout << "It sniffed your trace and came" << std::endl;
                sleep(5);
                std::cout << "\e[1;1H\e[2J";
                wolf(HP);
            }
            else if (temp < 3)
            {
                std::cout << "Seems that dangerous thing left" << std::endl;
                sleep(2);
                std::cout << "You go out and continue walking";
            }
            else if (temp < 6)
            {
                std::cout << "You move slowly backward" << std::endl;
                sleep(2);
                std::cout << "You step on a bear trap" << std::endl;
                sleep(2);
                std::cout << "Dang it" << std::endl;
                sleep(2);
                temp = rand() % 5 + 5;
                std::cout << "-" << temp << " HP" << std::endl;
                sleep(2);
                HP -= temp;
                if (HP <= 0)
                {
                    HP = 0;
                    break;
                }
                std::cout << "You open the trap and leave" << std::endl;
            }
            else
            {
                std::cout << "A snake crawls to your place" << std::endl;
                sleep(5);
                std::cout << "\e[1;1H\e[2J";
                snake(HP);
            }
        }
        if (option == 2)
        {
            std::cout << "You try not to make any noise while leaving this place" << std::endl;
            sleep(2);
            int temp = rand() % 10;
            if (temp == 0)
            {
                std::cout << "You step on a bear trap" << std::endl;
                sleep(2);
                std::cout << "So bad" << std::endl;
                sleep(2);
                temp = rand() % 5 + 5;
                std::cout << "-" << temp << " HP" << std::endl;
                sleep(2);
                HP -= temp;
                if (HP <= 0)
                {
                    HP = 0;
                    break;
                }
                std::cout << "You open the trap and leave" << std::endl;
            }
            else if (temp < 5)
            {
                std::cout << "You step on a dry branch" << std::endl;
                sleep(2);
                std::cout << "So quiet..." << std::endl;
                sleep(2);
                std::cout << "Something roars" << std::endl;
                sleep(2);
                std::cout << "A bear runs toward you" << std::endl;
                sleep(5);
                std::cout << "\e[1;1H\e[2J";
                bear(HP);
            }
            else
                std::cout << "You leave the area successfully" << std::endl;
        }
        if (option == 3)
        {
            std::cout << "You seek for the thing making that sound" << std::endl;
            sleep(2);
            std::cout << "You are walking" << std::endl;
            sleep(2);
            int temp = rand() % 20;
            if (temp < 3)
            {
                std::cout << "You only see a blood trace ahead" << std::endl;
                sleep(2);
                std::cout << "You follow it until no more trace" << std::endl;
                sleep(2);
                std::cout << "Can't do anything" << std::endl;
                sleep(2);
                std::cout << "You continue your way" << std::endl;
            }
            else if (temp < 6)
            {
                std::cout << "You see a dead human body" << std::endl;
                sleep(2);
                std::cout << "Such a bad omen man" << std::endl;
                sleep(2);
                temp = rand() % 6 + 13;
                std::cout << "You examined the body and found " << temp << " coins" << std::endl;
                sleep(2);
                std::cout << "+" << temp << " coin" << std::endl;
                coin += temp;
            }
            else if (temp < 14)
            {
                std::cout << "You see a dead deer" << std::endl;
                sleep(2);
                temp = rand() % 2 + 2;
                std::cout << "Cruel scene and you cut some meat from it" << std::endl;
                sleep(2);
                std::cout << "+" << temp << " raw meat" << std::endl;
                bag[1][5] += temp;
            }
            else
            {
                std::cout << "You see a bear" << std::endl;
                sleep(2);
                std::cout << "It turns around and roars at you" << std::endl;
                sleep(5);
                std::cout << "\e[1;1H\e[2J";
                bear(HP);
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
