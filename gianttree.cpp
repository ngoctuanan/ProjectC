#include "game_functions.h"


using namespace std;

void gianttree(int &eventcount)
{
    eventcount++;
    while (true)
    {
        cout << "HP: " << HP << endl;
        sleep(1);
        cout << "You across the forest and stop at a giant tree in front" << endl;
        sleep(2);
        cout << "You stand freeze before the tree" << endl;
        sleep(2);
        cout << "0. Open bag\n1. Explore around\n2. Climb on the tree\nYou decide to ";
        int option;
        cin >> option;
        cout << "\e[1;1H\e[2J";
        cout << "HP: " << HP << endl;
        sleep(1);

        if (option == 1)
        {
            cout << "You move around the tree many rounds until you notice something" << endl;
            sleep(2);
            int temp = rand() % 5;
            if (temp == 0)
            {
                cout << "You see a jungle cat" << endl;
                sleep(2);
                cout << "You want to tame it" << endl;
                sleep(2);
                cout << "You pat its head" << endl;
                sleep(2);
                cout << "It doesn't like it and scratches your face" << endl;
                sleep(2);
                cout << "-3 HP" << endl;
                sleep(2);
                HP -= 3;
                if (HP <= 0)
                {
                    sleep(2);
                    HP = 0;
                    break;
                }
                cout << "It leaves" << endl;
            }
            else if (temp == 1)
            {
                cout << "You see a hole deep down the root of the tree" << endl;
                sleep(2);
                cout << "You come close to the hole mouth" << endl;
                sleep(2);
                temp = rand() % 2;
                if (temp == 0)
                {
                    cout << "A rabbit jumps out" << endl;
                    sleep(2);
                    cout << "You chase and kill it" << endl;
                    sleep(2);
                    cout << "+1 raw meat" << endl;
                    bag[1][5]++;
                }
                else
                {
                    cout << "A snake jumps out and is ready to bite you" << endl;
                    sleep(5);
                    cout << "\e[1;1H\e[2J";
                    snake(HP);
                }
            }
            else
            {
                cout << "You find some edible mushrooms" << endl;
                sleep(2);
                cout << "Maybe can grill them later" << endl;
                sleep(2);
                cout << "You put them in your bag" << endl;
                sleep(2);
                temp = rand() % 3 + 3;
                cout << "+" << temp << " mushrooms" << endl;
                bag[1][8] += temp;
            }
        }
        if (option == 2)
        {
            cout << "You climb up the tree" << endl;
            sleep(2);
            cout << "So risky" << endl;
            sleep(2);
            int temp = rand() % 5;
            if (temp < 2)
            {
                cout << "You are halfway up" << endl;
                sleep(2);
                cout << "Your foot misses the branch" << endl;
                sleep(2);
                cout << "You fall" << endl;
                sleep(2);
                temp = rand() % 4 + 7;
                cout << "-" << temp << " HP" << endl;
                HP -= temp;
                if (HP <= 0)
                {
                    sleep(2);
                    HP = 0;
                    break;
                }
            }
            else if (temp == 2)
            {
                cout << "You see a hole of fruits on the way to the top of the tree" << endl;
                sleep(2);
                cout << "You steal the fruits no matter who they belong to" << endl;
                sleep(2);
                temp = rand() % 2 + 2;
                cout << "+" << temp << " apples\n+1 berry" << endl;
                sleep(2);
                bag[1][0] += temp;
                bag[1][1]++;
                cout << "You climb down" << endl;
            }
            else
            {
                cout << "You reach the top of the tree" << endl;
                sleep(2);
                cout << "So tired" << endl;
                sleep(2);
                temp = rand() % 5;
                if (temp < 3)
                {
                    cout << "You see a nest" << endl;
                    sleep(2);
                    cout << "You crawl to it" << endl;
                    sleep(2);
                    cout << "There are some eggs inside" << endl;
                    sleep(2);
                    cout << "You take the eggs" << endl;
                    sleep(2);
                    cout << "So cruel" << endl;
                    sleep(2);
                    temp = rand() % 2 + 3;
                    cout << "+" << temp << " eggs" << endl;
                    sleep(2);
                    bag[1][9] += temp;
                    cout << "You climb down" << endl;
                }
                else
                {
                    cout << "A lot of mushrooms grow up here" << endl;
                    sleep(2);
                    cout << "You collect them" << endl;
                    sleep(2);
                    temp = rand() % 3 + 5;
                    cout << "+" << temp << " mushrooms" << endl;
                    sleep(2);
                    bag[1][8] += temp;
                    cout << "You climb down" << endl;
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
