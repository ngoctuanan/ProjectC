#include "game_functions.h"

using namespace std;

void fishermanevent(int& eventcount)
{
    eventcount++;
    while (true) {
        cout << "HP: " << HP << endl;
        sleep(1);
        cout << "Along the river" << endl;
        sleep(2);
        cout << "You see someone fishing" << endl;
        sleep(2);
        cout << "0. Open bag" << endl;
        cout << "1. Come close" << endl;
        cout << "2. Ignore him" << endl;
        cout << "You decide to ";
        int option;
        cin >> option;
        cout << "\e[1;1H\e[2J";
        cout << "HP: " << HP << endl;
        sleep(1);
        if (option == 1) {
            cout << "For curiosity, you walk toward him" << endl;
            sleep(2);
            int temp = rand() % 20;
            if (temp < 2) {
                cout << "You say hi and he waves his hand toward you" << endl;
                sleep(2);
                cout << "He grabs the knife on his waist with the other hand and robs you" << endl;
                sleep(5);
                cout << "\e[1;1H\e[2J";
                thief(HP);
            }
            else if (temp < 8) {
                cout << "He was lucky today and caught a lot of fish" << endl;
                sleep(2);
                cout << "He gives you one" << endl;
                sleep(2);
                temp = rand() % 10;
                if (temp > 1) {
                    cout << "+1 small fish" << endl;
                    bag[1][2]++;
                }
                else {
                    cout << "+1 medium fish" << endl;
                    bag[1][3]++;
                }
            }
            else {
                cout << "He offers to buy some fish from you" << endl;
                sleep(2);
                if (bag[1][2] > 0 || bag[1][3] > 0 || bag[1][4] > 0) {
                    sleep(3);
                    while (bag[1][2] > 0 || bag[1][3] > 0 || bag[1][4] > 0) {
                        cout << "\e[1;1H\e[2J";
                        cout << "HP: " << HP << endl;
                        sleep(1);
                        int count = 0, *sell[] = { 0 };
                        while (count < 3) {
                            if (bag[1][2]) {
                                cout << count << ". Small fish=3 coins \tyou have " << bag[1][2] << "     ";
                                sell[count] = &bag[1][2];
                                count++;
                            }
                            if (bag[1][3]) {
                                cout << count << ". Medium fish=5 coins\tyou have " << bag[1][3] << "    ";
                                sell[count] = &bag[1][3];
                                count++;
                            }
                            if (bag[1][4]) {
                                cout << count << ". Large fish=7 coins \tyou have " << bag[1][4] << "     ";
                                sell[count] = &bag[1][4];
                                count++;
                            }
                            break;
                        }
                        cout << endl;
                        cout << count << ". Nothing" << endl;
                        cout << "You want to sell ";
                        int interoption;
                        cin >> interoption;
                        cout << "\e[1;1H\e[2J";
                        cout << "HP: " << HP << endl;
                        sleep(1);
                        if (sell[interoption] == &bag[1][2]) {
                            cout << "-1 small fish\n+3 coins" << endl;
                            sleep(2);
                            bag[1][2]--;
                            coin += 3;
                        }
                        if (sell[interoption] == &bag[1][3]) {
                            cout << "-1 medium fish\n+5 coins" << endl;
                            sleep(2);
                            bag[1][3]--;
                            coin += 5;
                        }
                        if (sell[interoption] == &bag[1][4]) {
                            cout << "-1 large fish\n+7 coins" << endl;
                            sleep(2);
                            bag[1][4]--;
                            coin += 7;
                        }
                        if (interoption == count) {
                            cout << "0. Confirm\n1. Maybe no\nLeave?\n";
                            cin >> interoption;
                            cout << "\e[1;1H\e[2J";
                           cout << "HP: " << HP << endl;
                            sleep(1);
                            if (interoption == 0)
                                break;
                        }
                    }
                    if (bag[1][2] == 0 && bag[1][3] == 0 && bag[1][4] == 0) {
                        cout << "You have no more fish to sell" << endl;
                        sleep(2);
                    }
                }
                else {
                    cout << "You have no fish to sell" << endl;
                    sleep(2);
                    cout << "He understood" << endl;
                    sleep(2);
                }
                cout << "You leave" << endl;
            }
        }
        if (option == 2) {
            cout << "You ignore that person and continue walking" << endl;
            sleep(2);
            int temp = rand() % 10;
            if (temp < 3) {
                cout << "That person does not let you go" << endl;
                sleep(2);
                cout << "He grabs your hand and points the knife at you" << endl;
                sleep(2);
                cout << "He seems to be a thief" << endl;
                sleep(5);
                cout << "\e[1;1H\e[2J";
                thief(HP);
            }
        }
        if (option == 0) {
            cout << "\e[1;1H\e[2J";
            int blockusegoods = 0;
            openbag(blockusegoods);
        }
        else {
            sleep(5);
            cout << "\e[1;1H\e[2J";
            break;
        }
    }
}