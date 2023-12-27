#include "game_functions.h"

using namespace std;

void fruitbasket(int &eventcount)
{
    eventcount++;
    while (true)
    {
        cout << "HP: " << HP << endl;
        sleep(1);
        cout << "You see a basket left beside the river" << endl;
        sleep(2);
        cout << "You come close and see that is the basket of fruits" << endl;
        sleep(2);
        cout << "0. Open bag\n1. Take all fruit\n2. Just take an apple\nYou decide to ";
        int option;
        cin >> option;
        cout << "\e[1;1H\e[2J";
        cout << "HP: " << HP << endl;
        sleep(1);

        if (option == 1)
        {
            cout << "You pick up the basket" << endl;
            sleep(2);
            int temp = rand() % 10;
            if (temp < 3)
            {
                cout << "A monkey appears and steals the basket from you" << endl;
                sleep(2);
                cout << "You can't let it have the basket" << endl;
                sleep(5);
                cout << "\e[1;1H\e[2J";
                monkey(HP);
                if (HP == 0)
                    break;
                else
                {
                    sleep(5);
                    cout << "\e[1;1H\e[2J";
                    cout << "HP: " << HP << endl;
                    sleep(1);
                    cout << "You take the basket back from the monkey" << endl;
                    sleep(2);
                }
            }
            cout << "From the basket you get" << endl;
            sleep(2);
            temp = rand() % 2 + 2;
            cout << "+" << temp << " apples" << endl;
            bag[1][0] += temp;
            cout << "+1 banana" << endl;
            bag[1][6]++;
            temp = rand() % 3 + 2;
            cout << "+" << temp << " berries" << endl;
            bag[1][1] += temp;
        }
        if (option == 2)
        {
            cout << "You take a look" << endl;
            sleep(2);
            cout << "You choose the best apple and take a bite" << endl;
            sleep(2);
            int temp = rand() % 4 + 7;
            cout << "+" << temp << " HP" << endl;
            HP += temp;
            if (HP > 100)
                HP = 100;
            temp = rand() % 5;
            if (temp == 0)
            {
                sleep(2);
                cout << "\nThe owner of the basket comes back right at the time to see you bite their fruit" << endl;
                sleep(2);
                cout << "She wants you to pay for that apple" << endl;
                sleep(2);
                if (coin >= 5)
                {
                    cout << "-5 coins" << endl;
                    coin -= 5;
                    sleep(2);
                    cout << "The woman takes the basket and leaves" << endl;
                }
                else if (coin == 0)
                {
                    cout << "You do not have any coin" << endl;
                    sleep(2);
                    cout << "The woman is angry" << endl;
                    sleep(2);
                    cout << "She takes the basket and leaves" << endl;
                }
                else
                {
                    cout << "-" << coin << " coin";
                    if (coin != 1)
                        cout << "s";
                    coin = 0;
                    sleep(2);
                    cout << endl;
                    cout << "The woman takes the basket and leaves" << endl;
                }
            }
        }
        
        if (option == 0)
        {
            cout << "\e[1;1H\e[2J";
            int blockusegoods = 0;
            openbag(blockusegoods);
        }
        else
        {
            sleep(5);
            cout << "\e[1;1H\e[2J";
            break;
        }
    }
}
