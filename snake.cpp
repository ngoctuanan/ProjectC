#include "game_functions.h"


using namespace std;

void snake(int &HP) {
    int snakeHP = 30;

    while (snakeHP > 0) {
        cout << "HP: " << HP << "\t\t\tSnake HP: " << snakeHP << endl;
        cout << "0. Open bag\n1. Attack\nLet's ";
        int option;
        cin >> option;
        cout << "\e[1;1H\e[2J";
        cout << "HP: " << HP << "\t\t\tSnake HP: " << snakeHP << endl;

        if (option == 1) {
            int temp = rand() % 20;
            if (temp == 0) {
                cout << "The snake dodged and you hit the ground" << endl;
            } else {
                temp = rand() % 5 + 8;
                cout << "You land a hit with " << temp << " damage on the snake" << endl;
                snakeHP -= temp;

                if (snakeHP <= 0) {
                    break;
                }
            }

            sleep(5);
            cout << "\e[1;1H\e[2J";
            cout << "HP: " << HP << "\t\t\tSnake HP: " << snakeHP << endl;

            temp = rand() % 100;
            if (temp < 7) {
                cout << "The snake attacks with a poisonous ball but you dodge" << endl;
            } else {
                temp = rand() % 3 + 3;
                cout << "The snake throws up a poisonous ball on you" << endl;
                cout << "-" << temp << " HP" << endl;
                HP -= temp;

                if (HP <= 0) {
                    sleep(2);
                    HP = 0;
                    break;
                }

                temp = rand() % 10;
                if (temp < 3) {
                    sleep(1);
                    cout << "Wait." << endl;
                    sleep(1);
                    cout << ".";
                    sleep(1);
                    cout << ".";
                    sleep(1);
                    cout << "." << endl;
                    sleep(1);
                    cout << "You get affected by poison" << endl;
                    cout << "-7 HP";
                    HP -= 7;

                    if (HP <= 0) {
                        sleep(2);
                        HP = 0;
                        break;
                    }
                }
            }

            sleep(5);
            cout << "\e[1;1H\e[2J";
        }

        if (option == 0) {
            cout << "\e[1;1H\e[2J";
            openbag(snakeHP);
        }
    }

    if (snakeHP <= 0) {
        sleep(5);
        cout << "\e[1;1H\e[2J";
        cout << "HP: " << HP << endl;
        sleep(1);
        cout << "The snake dies and you get" << endl;

        int temp = rand() % 4 + 3;
        cout << "+" << temp << " coins" << endl;
        coin += temp;

        temp = rand() % 10;
        if (temp != 0) {
            cout << "+1 raw meat" << endl;
            bag[1][5]++;
        }
    }
}
