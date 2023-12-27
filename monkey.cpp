#include "game_functions.h"


using namespace std;

void monkey(int &HP) {
    int monkeyHP = 40;

    while (monkeyHP > 0) {
        cout << "HP: " << HP << "\t\t\tMonkey HP: " << monkeyHP << endl;
        sleep(1);

        cout << "0. Open bag\n1. Attack\nLet's ";
        int option;
        cin >> option;

        cout << "\e[1;1H\e[2J";
        cout << "HP: " << HP << "\t\t\tMonkey HP: " << monkeyHP << endl;
        sleep(1);

        if (option == 1) {
            int temp = rand() % 20;

            if (temp == 0)
                cout << "You slash the monkey but it misses" << endl;
            else {
                temp = rand() % 5 + 8;
                cout << "You land the sword blade on the monkey and do " << temp << " damage" << endl;
                monkeyHP -= temp;
                sleep(2);

                if (monkeyHP <= 0)
                    break;
            }

            sleep(5);
            cout << "\e[1;1H\e[2J";
            cout << "HP: " << HP << "\t\t\tMonkey HP: " << monkeyHP << endl;
            sleep(1);

            temp = rand() % 25;

            if (temp == 0)
                cout << "The monkey punches your blade" << endl;
            else {
                temp = rand() % 3 + 7;
                cout << "The monkey punches in your face" << endl;
                sleep(2);
                cout << "-" << temp << " HP" << endl;
                HP -= temp;

                if (HP <= 0) {
                    sleep(2);
                    HP = 0;
                    break;
                }

                if (bag[1][0] || bag[1][1] || bag[1][6]) {
                    int count = 0, *steal[3] = {0};

                    if (bag[1][0]) {
                        steal[count] = &bag[1][0];
                        count++;
                    }

                    if (bag[1][1]) {
                        steal[count] = &bag[1][1];
                        count++;
                    }

                    if (bag[1][6])
                        steal[count] = &bag[1][6];

                    int eat;

                    while (bool keeprandom = true) {
                        eat = rand() % 3;

                        if (steal[eat] == &bag[1][0]) {
                            cout << "The monkey steals your apple and eats" << endl;
                            sleep(2);
                            cout << "-1 apple" << endl;
                            bag[1][0]--;
                            sleep(2);

                            int consume = rand() % 10;

                            if (consume == 0) {
                                cout << "The apple has a worm inside" << endl;
                                sleep(2);
                                cout << "Monkey -3 HP" << endl;
                                sleep(2);
                                monkeyHP -= 3;

                                if (monkeyHP <= 0)
                                    break;
                            } else {
                                consume = rand() % 3 + 5;
                                cout << "Juicy apple" << endl;
                                sleep(2);
                                cout << "Monkey +" << consume << " HP" << endl;
                                sleep(2);
                                monkeyHP += consume;

                                if (monkeyHP > 40)
                                    HP = 40;
                            }

                            break;
                        } else if (steal[eat] == &bag[1][1]) {
                            cout << "The monkey steals your berry and eats" << endl;
                            sleep(2);
                            cout << "-1 berry" << endl;
                            bag[1][1]--;
                            sleep(2);

                            int consume = rand() % 10;

                            if (consume == 0) {
                                cout << "The berry was rotten" << endl;
                                sleep(2);
                                cout << "Monkey -3 HP" << endl;
                                sleep(2);
                                monkeyHP -= 3;

                                if (monkeyHP <= 0)
                                    break;
                            } else {
                                consume = rand() % 2 + 2;
                                cout << "Fresh berry" << endl;
                                sleep(2);
                                cout << "Monkey +" << consume << " HP" << endl;
                                sleep(2);
                                monkeyHP += consume;

                                if (monkeyHP > 40)
                                    HP = 40;
                            }

                            break;
                        } else if (steal[eat] == &bag[1][6]) {
                            cout << "The monkey steals your banana and eats" << endl;
                            sleep(2);
                            cout << "-1 banana" << endl;
                            bag[1][6]--;
                            sleep(2);

                            int consume = rand() % 10;

                            if (consume == 0) {
                                cout << "The banana was out of date" << endl;
                                sleep(2);
                                cout << "Monkey -3 HP" << endl;
                                sleep(2);
                                monkeyHP -= 3;

                                if (monkeyHP <= 0)
                                    break;
                            } else {
                                consume = rand() % 2 + 3;
                                cout << "Yum banana" << endl;
                                sleep(2);
                                cout << "Monkey +" << consume << " HP" << endl;
                                sleep(2);
                                monkeyHP += consume;

                                if (monkeyHP > 40)
                                    HP = 40;
                            }

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
            openbag(monkeyHP);
        }
    }

    if (monkeyHP <= 0) {
        sleep(5);
        cout << "\e[1;1H\e[2J";
        cout << "HP: " << HP << endl;
        sleep(1);
        cout << "You defeat the monkey" << endl;
        sleep(2);

        int temp = rand() % 3 + 3;
        cout << "You got" << endl;
        sleep(2);
        cout << "+" << temp << " coins" << endl;
        sleep(2);
        coin += temp;

        cout << "You found some bananas in its dead body" << endl;
        sleep(2);

        temp = rand() % 2 + 2;
        cout << "+" << temp << " bananas" << endl;
        bag[1][6] += temp;
    }
}
