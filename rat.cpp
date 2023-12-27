#include "game_functions.h"


using namespace std;

void rat(int &HP) {
    int ratHP = 18;

    while (ratHP > 0) {
        cout << "HP: " << HP << "\t\t\tRat HP: " << ratHP << endl;
        sleep(1);

        cout << "0. Open bag\n1. Attack\nLet's ";
        int option;
        cin >> option;

        cout << "\e[1;1H\e[2J";
        cout << "HP: " << HP << "\t\t\tRat HP: " << ratHP << endl;
        sleep(1);

        if (option == 1) {
            int temp = rand() % 20;

            if (temp == 0)
                cout << "The rat is small, so you cannot hit it accurately" << endl;
            else {
                temp = rand() % 5 + 8;
                cout << "You land a hit with " << temp << " damage on the rat" << endl;
                ratHP -= temp;

                if (ratHP <= 0)
                    break;
            }

            sleep(5);
            cout << "\e[1;1H\e[2J";
            cout << "HP: " << HP << "\t\t\tRat HP: " << ratHP << endl;
            sleep(1);

            temp = rand() % 50;

            if (temp == 0)
                cout << "The rat jumps to bite you, but you block it" << endl;
            else {
                temp = rand() % 2 + 1;
                cout << "The rat bites you" << endl;
                sleep(2);
                cout << "-" << temp << " HP" << endl;
                HP -= temp;

                if (HP <= 0) {
                    sleep(2);
                    HP = 0;
                    break;
                }

                temp = rand() % 2;

                if (temp == 0) {
                    sleep(2);
                    cout << "It quickly bites you again" << endl;
                    sleep(2);
                    temp = rand() % 2 + 1;
                    cout << "-" << temp << " HP" << endl;
                    HP -= temp;

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
            openbag(ratHP);
        }
    }

    if (ratHP <= 0) {
        sleep(5);
        cout << "\e[1;1H\e[2J";
        cout << "HP: " << HP << endl;
        sleep(1);
        cout << "You kill the rat" << endl;
        sleep(2);

        int temp = rand() % 2 + 2;
        cout << "You got" << endl;
        sleep(2);
        cout << "+" << temp << " coins" << endl;
        coin += temp;

        temp = rand() % 2;

        if (temp == 0) {
            sleep(2);
            cout << "This rat was big enough for you to take its meat" << endl;
            sleep(2);
            cout << "+1 raw meat" << endl;
            bag[1][5]++;
        }
    }
}
