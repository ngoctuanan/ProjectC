#include "game_functions.h"
using namespace std;

void food()
{
    bool keeppocketopen = true;
    while (keeppocketopen)
    {
        cout << "HP: " << HP << "\t\t\tCoin: " << coin << endl;
        int count = 0, *temp[] = {0};
        if (bag[1][0])
        {
            cout << count << ". " << sleep(5) << "Apple: " << bag[1][0] << "          ";
            temp[count] = &bag[1][0];
            count++;
        }
        if (bag[1][1])
        {
            cout << count << ". " << sleep(5) << "Berry: " << bag[1][1] << "          ";
            temp[count] = &bag[1][1];
            count++;
        }
        if (bag[1][2])
        {
            cout << count << ". " << sleep(10) << "Small fish: " << bag[1][2] << "     ";
            temp[count] = &bag[1][2];
            count++;
        }
        if (bag[1][3])
        {
            cout << count << ". " << sleep(11) << "Medium fish: " << bag[1][3] << "    ";
            temp[count] = &bag[1][3];
            count++;
        }
        if (bag[1][4])
        {
            cout << count << ". " <<sleep(10) << "Large fish: " << bag[1][4] << "     ";
            temp[count] = &bag[1][4];
            count++;
        }
        if (bag[1][5])
        {
            cout << count << ". " << sleep(8) << "Raw meat: " << bag[1][5] << "     ";
            temp[count] = &bag[1][5];
            count++;
        }
        cout << endl;
        if (bag[1][6])
        {
            cout << count << ". " << sleep(6) << "Banana: " << bag[1][6] << "         ";
            temp[count] = &bag[1][6];
            count++;
        }
        if (bag[1][8])
        {
            cout << count << ". " << sleep(8) << "Mushroom: " << bag[1][8] << "       ";
            temp[count] = &bag[1][8];
            count++;
        }
        if (bag[1][9])
        {
            cout << count << ". " << sleep(3) << "Egg: " << bag[1][9] << "            ";
            temp[count] = &bag[1][9];
            count++;
        }
        cout << "\n\n";
        cout << count << ". Nothing\nYou want to consume ";
        int option;
        cin >> option;
        cout << "\e[1;1H\e[2J";
        cout << "HP: " << HP << "\t\t\tCoin: " << coin << endl;
        sleep(1);

        if (temp[option] == &bag[1][0])
        {
            bag[1][0]--;
            int consume = rand() % 10;
            if (consume == 0)
            {
                cout << "The apple has a worm inside" << endl;
                sleep(2);
                cout << "-3 HP" << endl;
                sleep(2);
                cout << "\e[1;1H\e[2J";
                HP -= 3;
                if (HP < 0)
                {
                    HP = 0;
                    break;
                }
            }
            else
            {
                consume = rand() % 3 + 5;
                cout << "Juicy apple" << endl;
                sleep(2);
                cout << "+" << consume << " HP" << endl;
                sleep(2);
                cout << "\e[1;1H\e[2J";
                HP += consume;
                if (HP > 100)
                    HP = 100;
            }
        }
        if (temp[option] == &bag[1][1])
        {
            bag[1][1]--;
            int consume = rand() % 10;
            if (consume == 0)
            {
                cout << "The berry was rotten" << endl;
                sleep(2);
                cout << "-3 HP" << endl;
                sleep(2);
                cout << "\e[1;1H\e[2J";
                HP -= 3;
                if (HP < 0)
                {
                    HP = 0;
                    break;
                }
            }
            else
            {
                consume = rand() % 2 + 2;
                cout << "Fresh berry" << endl;
                sleep(2);
                cout << "+" << consume << " HP" << endl;
                sleep(2);
                cout << "\e[1;1H\e[2J";
                HP += consume;
                if (HP > 100)
                    HP = 100;
            }
        }
        if (temp[option] == &bag[1][2])
        {
            bag[1][2]--;
            int consume = rand() % 4;
            if (consume == 0)
            {
                cout << "You get poison from eating raw food" << endl;
                sleep(2);
                cout << "-7 HP" << endl;
                sleep(2);
                cout << "\e[1;1H\e[2J";
                HP -= 7;
                if (HP < 0)
                {
                    HP = 0;
                    break;
                }
            }
            else
            {
                cout << "Small fish does not supply much vitamins" << endl;
                sleep(2);
                cout << "It is even raw" << endl;
                sleep(2);
                cout << "+3 HP" << endl;
                sleep(2);
                cout << "\e[1;1H\e[2J";
                HP += 3;
                if (HP > 100)
                    HP = 100;
            }
        }
        if (temp[option] == &bag[1][3])
        {
            bag[1][3]--;
            int consume = rand() % 4;
            if (consume == 0)
            {
                cout << "You get poison from eating raw food" << endl;
                sleep(2);
                cout << "-7 HP" << endl;
                sleep(2);
                cout << "\e[1;1H\e[2J";
                HP -= 7;
                if (HP < 0)
                {
                    HP = 0;
                    break;
                }
            }
            else
            {
                consume = rand() % 2 + 4;
                cout << "Raw medium fish gives fine taste" << endl;
                sleep(2);
                cout << "+" << consume << " HP" << endl;
                sleep(2);
                cout << "\e[1;1H\e[2J";
                HP += consume;
                if (HP > 100)
                    HP = 100;
            }
        }
        if (temp[option] == &bag[1][4])
        {
            bag[1][4]--;
            int consume = rand() % 4;
            if (consume == 0)
            {
                cout << "You get poison from eating raw food" << endl;
                sleep(2);
                cout << "-7 HP" << endl;
                sleep(2);
                cout << "\e[1;1H\e[2J";
                HP -= 7;
                if (HP < 0)
                {
                    HP = 0;
                    break;
                }
            }
            else
            {
                cout << "Large fish is delicious" << endl;
                sleep(2);
                cout << "But is raw" << endl;
                sleep(2);
                cout << "+6 HP" << endl;
                sleep(2);
                cout << "\e[1;1H\e[2J";
                HP += 6;
                if (HP > 100)
                    HP = 100;
            }
        }
        if (temp[option] == &bag[1][5])
        {
            bag[1][5]--;
            int consume = rand() % 4;
            if (consume == 0)
            {
                cout << "You get poison from eating raw food" << endl;
                sleep(2);
                cout << "-7 HP" << endl;
                sleep(2);
                cout << "\e[1;1H\e[2J";
                HP -= 7;
                if (HP < 0)
                {
                    HP = 0;
                    break;
                }
            }
            else
            {
                cout << "Raw meat does not supply much vitamins" << endl;
                sleep(2);
                cout << "+4 HP" << endl;
                sleep(2);
                cout << "\e[1;1H\e[2J";
                HP += 4;
                if (HP > 100)
                    HP = 100;
            }
        }
        if (temp[option] == &bag[1][6])
        {
            bag[1][6]--;
            int consume = rand() % 10;
            if (consume == 0)
            {
                cout << "The banana was out of date" << endl;
                sleep(2);
                cout << "-3 HP" << endl;
                sleep(2);
                cout << "\e[1;1H\e[2J";
                HP -= 3;
                if (HP < 0)
                {
                    HP = 0;
                    break;
                }
            }
            else
            {
                consume = rand() % 2 + 3;
                cout << "Yum banana" << endl;
                sleep(2);
                cout << "+" << consume << " HP" << endl;
                sleep(2);
                cout << "\e[1;1H\e[2J";
                HP += consume;
                if (HP > 100)
                    HP = 100;
            }
        }
        if (temp[option] == &bag[1][8])
        {
            bag[1][8]--;
            int consume = rand() % 4;
            if (consume == 0)
            {
                cout << "A poisonous mushroom grow on the mushroom you ate" << endl;
                sleep(2);
                cout << "-7 HP" << endl;
                sleep(2);
                cout << "\e[1;1H\e[2J";
                HP -= 7;
                if (HP < 0)
                {
                    HP = 0;
                    break;
                }
            }
            else
            {
                consume = rand() % 3 + 2;
                cout << "Wild mushroom supply you some health" << endl;
                sleep(2);
                cout << "+" << consume << " HP" << endl;
                sleep(2);
                cout << "\e[1;1H\e[2J";
                HP += consume;
                if (HP > 100)
                    HP = 100;
            }
        }
        if (temp[option] == &bag[1][9])
        {
            bag[1][9]--;
            cout << "You just ate an uncooked egg?" << endl;
            sleep(2);
            cout << "So boid" << endl;
            sleep(2);
            cout << "+4 HP" << endl;
            sleep(2);
            HP += 4;
            cout << "\e[1;1H\e[2J";
            if (HP > 100)
                HP = 100;
        }
        if (option == count)
        {
            cout << "0. Confirm\n1. Ehh...\nClose pocket?\n";
            cin >> option;
            cout << "\e[1;1H\e[2J";
            if (option == 0)
                break;
        }
    }
}
