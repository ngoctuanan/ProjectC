#include "game_functions.h"


using namespace std;

void wolf(int &HP) {
    int wolfHP = 55;
    while (wolfHP > 0) {
        cout << "HP: " << HP << "\t\t\tWolf HP: " << wolfHP << endl;
        sleep(1);
        cout << "0. Open bag\n1. Attack\nLet's ";

        int option;
        cin >> option;

        cout << "\e[1;1H\e[2J";
        cout << "HP: " << HP << "\t\t\tWolf HP: " << wolfHP << endl;
        sleep(1);

        if (option == 1) {
            int temp = rand() % 20;
            if (temp == 0) {
                cout << "You stab the wolf but it jumps back" << endl;
            } else {
                temp = rand() % 5 + 8;
                cout << "You kick the sword hilt and it stabs the wolf with " << temp << " damage" << endl;
                wolfHP -= temp;
                sleep(2);
                cout << "You avoid the wolf and take the sword back" << endl;
                if (wolfHP <= 0) {
                    break;
                }
            }
            sleep(5);
            cout << "\e[1;1H\e[2J";
            cout << "HP: " << HP << "\t\t\tWolf HP: " << wolfHP << endl;
            sleep(1);
            temp = rand() % 25;
            if (temp < 2) {
                cout << "The wolf bites you but you dodge and it bites the air surrounding you instead" << endl;
            } else {
                temp = rand() % 2 + 9;
                cout << "The wolf damages you with its claws" << endl;
                sleep(2);
                cout << "- " << temp << " HP" << endl;
                HP -= temp;
                if (HP <= 0) {
                    sleep(2);
                    HP = 0;
                    break;
                }
                temp = rand() % 10;
                if (temp == 0) {
                    sleep(2);
                    cout << "That was a deep bite" << endl;
                    sleep(2);
                    cout << "The wound starts bleeding" << endl;
                    sleep(2);
                    cout << "-5 HP" << endl;
                    HP -= 5;
                    if (HP <= 0) {
                        sleep(2);
                        HP = 0;
                        break;
                    }
                    temp = rand() % 4;
                    if (temp < 3) {
                        sleep(2);
                        cout << "It keeps bleeding" << endl;
                        sleep(2);
                        cout << "-5 HP" << endl;
                        HP -= 5;
                        if (HP <= 0) {
                            sleep(2);
                            HP = 0;
                            break;
                        }
                    }
                }
            }
            sleep(5);
            cout << "\e[1;1H\e[2J";
        }
        if (option == 0) {
            cout << "\e[1;1H\e[2J";
            openbag(wolfHP);
        }
    }
    if (wolfHP <= 0) {
        sleep(5);
        cout << "\e[1;1H\e[2J";
        cout << "HP: " << HP << endl;
        sleep(1);
        cout << "You defeat the wolf" << endl;
        sleep(2);
        cout << "That was..." << endl;
        sleep(2);
        int temp = rand() % 2 + 9;
        cout << "You got" << endl;
        sleep(2);
        cout << "+ " << temp << " coins" << endl;
        sleep(2);
        coin += temp;
        cout << "You slash some meat from the wolf dead body" << endl;
        sleep(2);
        cout << "+2 raw meat" << endl;
        bag[1][5] += 2;
    }
}
