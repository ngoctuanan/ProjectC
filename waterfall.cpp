#include "game_functions.h"


using namespace std;

void waterfall(int &eventcount) {
    eventcount++;
    while (bool keepevent = true) {
        cout << "HP: " << HP << endl;
        sleep(1);
        cout << "You follow the river flow and see another branch of the river come from a waterfall nearby" << endl;
        sleep(2);
        cout << "You come toward the waterfall" << endl;
        sleep(2);
        cout << "There is a way lead to the cave behind the waterfall" << endl;
        sleep(2);
        cout << "0. Open bag\n1. Go inside the cave\n2. Explore around the waterfall\nYou decide to ";
        
        int option;
        cin >> option;

        cout << "\e[1;1H\e[2J";
        cout << "HP: " << HP << endl;
        sleep(1);

        if (option == 1) {
            cout << "You head inside the cave" << endl;
            sleep(2);
            cout << "You take a look" << endl;
            int temp = rand() % 10;
            if (temp < 2) {
                cout << "Seem mushroom is thriving inside the cave" << endl;
                sleep(2);
                cout << "You take some mushrooms and put them in your bag" << endl;
                sleep(2);
                int temp1 = rand() % 2 + 3;
                cout << "+ " << temp1 << " mushrooms" << endl;
                bag[1][8] += temp1;
            } else {
                cout << "This seems to be a bat cave" << endl;
                sleep(2);
                int temp1 = rand() % 10;
                if (temp1 < 6) {
                    cout << "The cave is filled with fruits" << endl;
                    sleep(2);
                    cout << "But you don't see any bats" << endl;
                    sleep(2);
                    cout << "Maybe they are collecting more fruits outside" << endl;
                    sleep(2);
                    cout << "You collect these fruits" << endl;
                    sleep(2);
                    int temp2 = rand() % 2 + 4;
                    cout << "+ " << temp2 << " apples" << endl;
                    bag[1][0] += temp2;
                    cout << "+2 berries" << endl;
                    bag[1][1] += 2;
                } else {
                    cout << "The bats are hanging to sleep" << endl;
                    sleep(2);
                    cout << "You see nothing to take and leave" << endl;
                    sleep(2);
                    cout << "You kick a rock accidentally and wake a bat up" << endl;
                    sleep(2);
                    cout << "It attacks you" << endl;
                    sleep(5);
                    cout << "\e[1;1H\e[2J";
                    bat(HP);
                }
            }
        }

        if (option == 2) {
            cout << "You go explore the habitat below the waterfall" << endl;
            sleep(2);
            int temp1 = rand() % 20;
            if (temp1 < 2) {
                cout << "You bend down to check the flow" << endl;
                sleep(2);
                cout << "Suddenly a bat flys out of the cave" << endl;
                sleep(2);
                cout << "It sees you and wants to take your bag" << endl;
                sleep(2);
                cout << "You can't let it have it" << endl;
                sleep(5);
                cout << "\e[1;1H\e[2J";
                bat(HP);
            } else if (temp1 < 5) {
                cout << "You keep walking around and a fish falls on your head" << endl;
                sleep(2);
                cout << "-3 HP" << endl;
                HP -= 3;
                if (HP <= 0) {
                    sleep(2);
                    HP = 0;
                    break;
                }
                sleep(2);
                int temp2 = rand() % 10;
                cout << "It must come from the upper waterfall" << endl;
                sleep(2);
                cout << "You just grab the fish and throw it into your bag anyway" << endl;
                sleep(2);
                if (temp2 < 7) {
                    cout << "+1 small fish" << endl;
                    bag[1][2]++;
                } else {
                    cout << "+1 medium fish" << endl;
                    bag[1][3]++;
                }
            } else if (temp1 < 9) {
                cout << "Look at the water" << endl;
                sleep(2);
                cout << "You see a bomb" << endl;
                sleep(2);
                cout << "Did someone catch fish by exploding?" << endl;
                sleep(2);
                cout << "You grab the bomb" << endl;
                sleep(2);
                int temp2 = rand() % 10;
                if (temp2 < 4) {
                    cout << "The bomb goes off" << endl;
                    sleep(2);
                    cout << "-18 HP" << endl;
                    HP -= 18;
                    if (HP <= 0) {
                        sleep(2);
                        HP = 0;
                        break;
                    }
                } else {
                    cout << "The bomb may work well" << endl;
                    sleep(2);
                    cout << "You put it in the bag" << endl;
                    sleep(2);
                    cout << "+1 bomb" << endl;
                    bag[3][2]++;
                }
            } else {
                cout << "You see an apple tree and come to examine" << endl;
                sleep(2);
                cout << "You shake the tree" << endl;
                sleep(2);
                int temp2 = rand() % 4;
                if (temp2 == 0) {
                    cout << "A bee hive falls on your head" << endl;
                    sleep(2);
                    cout << "You get stung" << endl;
                    sleep(2);
                    cout << "-8 HP" << endl;
                    HP -= 8;
                    if (HP <= 0) {
                        sleep(2);
                        HP = 0;
                        break;
                    }
                } else if (temp2 == 1) {
                    cout << "A bat falls off" << endl;
                    sleep(2);
                    cout << "It is eating and you do this to it?" << endl;
                    sleep(2);
                    cout << "It turns angry and attacks you" << endl;
                    sleep(5);
                    cout << "\e[1;1H\e[2J";
                    bat(HP);
                } else {
                    cout << "Some apples fall off" << endl;
                    sleep(2);
                    cout << "You take them" << endl;
                    sleep(2);
                    int temp3 = rand() % 3 + 2;
                    cout << "+ " << temp3 << " apples" << endl;
                    bag[1][0] += temp3;
                }
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
