#include "game_functions.h"

using namespace std;

void restblurwaterevent(int &eventcount) {
    eventcount++;

    while (bool keepevent = true) {
        cout << "HP: " << HP << endl;
        sleep(1);

        cout << "You feel tired and decide to take a rest" << endl;
        sleep(2);

        cout << "This part of the river has blurry water" << endl;
        sleep(2);

        cout << "You stare at the water" << endl;
        sleep(2);

        cout << "0. Open bag\n1. Jump into the river\n2. Gather some material\nYou decide to ";
        int option;
        cin >> option;

        cout << "\e[1;1H\e[2J";
        cout << "HP: " << HP << endl;
        sleep(1);

        if (option == 1) {
            cout << "You wonder what is under that water" << endl;
            sleep(2);

            cout << "You jump into the river" << endl;
            sleep(2);

            int temp = rand() % 10;

            if (temp == 0) {
                cout << "A big shadow swimming around you" << endl;
                sleep(2);
                cout << "It disappears";
                sleep(1);
                cout << ".";
                sleep(1);
                cout << ".";
                sleep(1);
                cout << ".";
                sleep(2);
                cout << endl;
                cout << "You swim to the land real quick but didn't make it" << endl;
                sleep(2);
                cout << "That thing bites your leg" << endl;
                sleep(2);

                int temp1 = rand() % 6 + 10;
                cout << "-" << temp1 << " HP" << endl;
                sleep(2);
                HP -= temp1;

                if (HP <= 0) {
                    sleep(2);
                    HP = 0;
                    break;
                }

                cout << "You try to kick it with the other leg" << endl;
                sleep(2);
                cout << "It falls off, and you make it to the land" << endl;
            } else if (temp < 3) {
                cout << "You dive down and look for some fishes" << endl;
                sleep(2);
                cout << "But you don't see any" << endl;
                sleep(2);
                cout << "A snake bites you underwater" << endl;
                sleep(2);

                int temp1 = rand() % 3 + 3;
                cout << "-" << temp1 << " HP" << endl;
                sleep(2);
                HP -= temp1;

                if (HP <= 0) {
                    sleep(2);
                    HP = 0;
                    break;
                }

                cout << "You pull it and throw it away" << endl;
                sleep(2);
                cout << "You swim to the land, and it doesn't give up" << endl;
                sleep(2);
                cout << "The snake follows you" << endl;
                sleep(5);

                cout << "\e[1;1H\e[2J";
                snake(HP);
            } else {
                cout << "With your special skill" << endl;
                sleep(2);
                cout << "You catch a ";

                int temp1 = rand() % 10;

                if (temp1 < 3) {
                    int temp2 = rand() % 3;

                    if (temp2 == 0) {
                        cout << "smallmouth bass" << endl;
                        sleep(2);
                    }

                    if (temp2 == 1) {
                        cout << "perch" << endl;
                        sleep(2);
                    }

                    if (temp2 == 2) {
                        cout << "bream" << endl;
                        sleep(2);
                    }

                    int temp3 = rand() % 4;

                    if (temp3 == 0) {
                        cout << "But the fish is slippery" << endl;
                        sleep(2);
                        cout << "It jumps off your hands and swims away" << endl;
                    } else {
                        cout << "+1 small fish" << endl;
                        bag[1][2]++;
                    }
                } else {
                    int temp2 = rand() % 3;

                    if (temp2 == 0) {
                        cout << "rainbow trout" << endl;
                        sleep(2);
                    }

                    if (temp2 == 1) {
                        cout << "walleye" << endl;
                        sleep(2);
                    }

                    if (temp2 == 2) {
                        cout << "pike" << endl;
                        sleep(2);
                    }

                    int temp3 = rand() % 2;

                    if (temp3 == 0) {
                        cout << "But the fish is slippery" << endl;
                        sleep(2);
                        cout << "It jumps off your hands and swims away" << endl;
                    } else {
                        cout << "+1 medium fish" << endl;
                        bag[1][3]++;
                    }
                }
            }
        }

        if (option == 2) {
            cout << "You search for something useful to use" << endl;
            sleep(2);

            cout << "You push the high grasses aside" << endl;
            sleep(2);

            int temp = rand() % 20;

            if (temp == 0) {
                cout << "You see a snake trembling" << endl;
                sleep(2);
                cout << "It is scared of something but then attacks you to defend itself" << endl;
                sleep(5);

                cout << "\e[1;1H\e[2J";
                snake(HP);
            } else if (temp == 1) {
                cout << "You see a tiny rope near a damaged stone" << endl;
                sleep(2);
                cout << "You pull it up" << endl;
                sleep(2);
                cout << "It is a bomb which you do not know if it still works" << endl;
                sleep(2);
                cout << "+1 bomb" << endl;
                sleep(2);
                bag[3][1]++;
                cout << "You take some stones with you too" << endl;
                sleep(2);

                int temp1 = rand() % 2 + 2;
                cout << "+" << temp1 << " stones" << endl;
                bag[2][1] += temp1;
            } else if (temp < 19) {
                cout << "You see some mice" << endl;
                sleep(2);
                cout << "They see you and run away" << endl;
                sleep(2);
                cout << "But one of them stays and holds your step" << endl;
                sleep(5);

                cout << "\e[1;1H\e[2J";
                rat(HP);
            } else {
                cout << "Just clays and rocks" << endl;
                sleep(2);
                cout << "You put them in the bag" << endl;
                sleep(2);

                int temp1 = rand() % 3 + 2;
                cout << "+" << temp1 << " clays" << endl;
                sleep(2);
                bag[2][0] += temp1;

                int temp2 = rand() % 3 + 2;
                cout << "+" << temp2 << " rocks" << endl;
                sleep(2);
                bag[3][0] += temp2;

                cout << "After taking out clays and rocks, you see some coins" << endl;
                sleep(2);

                int temp3 = rand() % 3 + 2;
                cout << "+" << temp3 << " coins" << endl;
                coin += temp3;
            }
        }

        if (option == 0) {
            cout << "\e[1;1H\e[2J";
            int blockusegoods = 0;
            openbag(blockusegoods);
        } else {
            sleep(5);
            cout << "\e[1;1H\e[2J";
            break;
        }
    }
}
