#include "game_functions.h"
#include <iostream>

using namespace std;

void goods(int &enemyHP) {
    bool keeppocketopen = true;

    while (keeppocketopen) {
        cout << "HP: " << HP << "\t\t\tCoin: " << coin << endl;

        int count = 0, *temp[2] = {0};

        while (count < 2) {
            if (count % 5 == 0)
                cout << endl;

            if (bag[3][0]) {
                cout << count << ". " << sleep(4) << "Rock: " << bag[3][0] << "         ";
                temp[count] = &bag[3][0];
                count++;
            }

            if (bag[3][1]) {
                cout << count << ". " << sleep(4) << "Bomb: " << bag[3][1] << "         ";
                temp[count] = &bag[3][1];
                count++;
            }

            break;
        }

        cout << "\n\n";

        if (enemyHP > 0) {
            cout << count << ". Nothing\nYou want to use ";
            int option, missrate = rand() % 20;
            cin >> option;

            cout << "\e[1;1H\e[2J";
            cout << "HP: " << HP << "\t\t\tCoin: " << coin << endl;
            sleep(1);

            if (temp[option] == &bag[3][0])
                bag[3][0]--;

            if (temp[option] == &bag[3][1])
                bag[3][1]--;

            if (option != count) {
                if (missrate == 0) {
                    cout << "." << flush;
                    sleep(1);
                    cout << "." << flush;
                    sleep(1);
                    cout << "." << flush;
                    sleep(1);
                    cout << endl;
                    sleep(2);
                    cout << "As expected" << endl;
                    sleep(2);
                    cout << "Due to your bad throwing skill" << endl;
                    sleep(2);
                    cout << "The thing you threw flies over the enemy and lands on a point far away from the enemy..." << endl;
                    sleep(2);
                    cout << "welp..." << endl;
                    sleep(2);
                    cout << "\e[1;1H\e[2J";
                } else {
                    if (temp[option] == &bag[3][0]) {
                        cout << "You throw a rock and it hits the enemy's head and does 4 damage" << endl;
                        sleep(3);
                        cout << "\e[1;1H\e[2J";
                        enemyHP -= 4;
                        if (enemyHP < 0)
                            enemyHP = 0;
                    }

                    if (temp[option] == &bag[3][1]) {
                        cout << "You throw a bomb beside the enemy" << endl;
                        sleep(2);
                        cout << "It explodes and does 18 damage" << endl;
                        sleep(3);
                        cout << "\e[1;1H\e[2J";
                        enemyHP -= 18;
                        if (enemyHP < 0)
                            enemyHP = 0;
                    }
                }
            }

            if (option == count) {
                cout << "0. Confirm\n1. Ehh...\nClose pocket?\n";
                cin >> option;
                cout << "\e[1;1H\e[2J";
                if (option == 0)
                    break;
            }
        } else {
            cout << "0. Confirm\n1. Ehh...\nClose pocket?\n";
            int option;
            cin >> option;
            cout << "\e[1;1H\e[2J";
            if (option == 0)
                break;
        }
    }
}
