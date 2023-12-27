#include "game_functions.h"


using namespace std;

void thief(int &HP) {
    int thiefHP = 50, thiefbag = 0;

    while (thiefHP > 0) {
        cout << "HP: " << HP << "\t\t\tThief HP: " << thiefHP << endl;
        sleep(1);
        cout << "0. Open bag\n1. Attack\nLet's ";

        int option;
        cin >> option;

        cout << "\e[1;1H\e[2J";
        cout << "HP: " << HP << "\t\t\tThief HP: " << thiefHP << endl;
        sleep(1);

        if (option == 1) {
            int temp = rand() % 20;
            if (temp == 0) {
                cout << "The thief dodged and you land your attack in the air" << endl;
            } else {
                temp = rand() % 5 + 8;
                cout << "You land a hit with " << temp << " damage on him" << endl;
                thiefHP -= temp;
                if (thiefHP <= 0) break;
            }

            sleep(5);
            cout << "\e[1;1H\e[2J";
            cout << "HP: " << HP << "\t\t\tThief HP: " << thiefHP << endl;

            temp = rand() % 20;
            if (temp == 0) {
                cout << "Thief guess he cannot defeat you" << endl;
                sleep(2);
                cout << "He runs away" << endl;
                sleep(2);
                break;
            } else {
                temp = rand() % 10;
                if (temp == 0) {
                    cout << "You step back and his knife just almost touch your face" << endl;
                    sleep(2);
                    cout << "He misses" << endl;
                } else {
                    temp = rand() % 3 + 5;
                    cout << "He slashes you with the knife" << endl;
                    sleep(2);
                    cout << "That is hurt" << endl;
                    sleep(2);
                    cout << "- " << temp << " HP" << endl;
                    HP -= temp;
                    if (HP <= 0) {
                        HP = 0;
                        break;
                    }

                    if (coin == 1) {
                        cout << "He stole a coin from you before you realized" << endl;
                        sleep(2);
                        cout << "-1 coin" << endl;
                        coin--;
                        thiefbag++;
                    }

                    if (coin > 1) {
                        temp = rand() % 2 + 1;
                        if (temp == 1) {
                            cout << "He stole a coin from you before you realized" << endl;
                            sleep(2);
                            cout << "-1 coin" << endl;
                            coin--;
                            thiefbag++;
                        } else {
                            cout << "He stole 2 coins from you before you realized" << endl;
                            sleep(2);
                            cout << "-2 coins" << endl;
                            coin -= 2;
                            thiefbag += 2;
                        }
                    }
                }
            }

            sleep(5);
            cout << "\e[1;1H\e[2J";
        }

        if (option == 0) {
            cout << "\e[1;1H\e[2J";
            openbag(thiefHP);
        }
    }

    if (thiefHP <= 0) {
        sleep(5);
        cout << "\e[1;1H\e[2J";
        cout << "HP: " << HP << endl;
        sleep(1);
        cout << "You knock down the thief but you cannot kill people" << endl;
        sleep(2);

        if (thiefbag > 0) {
            cout << "You get your coins back from him" << endl;
            sleep(2);

            if (thiefbag == 1) {
                cout << "+1 coin" << endl;
                coin++;
            } else {
                cout << "+ " << thiefbag << " coins" << endl;
                coin += thiefbag;
            }

            cout << "And his coins" << endl;

            int temp = rand() % 6 + 15;
            cout << "+ " << temp << " coins" << endl;
            coin += temp;
        } else {
            cout << "You take some coins from him" << endl;
            sleep(2);

            int temp = rand() % 6 + 15;
            cout << "+ " << temp << " coins" << endl;
            coin += temp;
        }
    }
}
