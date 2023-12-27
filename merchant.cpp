#include "game_functions.h"


using namespace std;

void merchant(int &eventcount) {
    eventcount++;
    int choice;

    while (true) {
        cout << "HP: " << HP << endl;
        sleep(1);

        cout << "You see an old man standing under a tree" << endl;
        sleep(2);

        cout << "You step forward and he calls out to you" << endl;
        sleep(2);

        cout << "The old man is a merchant and he invites you to buy his goods" << endl;
        sleep(2);

        cout << "\e[1;1H\e[2J";

        do {
            cout << "Welcome to Merchain's shop!" << endl;
            sleep(1);

            cout << "0. Open bag" << endl;
            sleep(1);

            cout << "1. Buy Weapon" << endl;
            sleep(1);

            cout << "2. Buy Equipment" << endl;
            sleep(1);

            cout << "3. Exit" << endl;
            sleep(2);

            cout << "Now! Tell me your option boy: ";
            cin >> choice;

            cout << "\e[1;1H\e[2J";

            int demo;

            switch (choice) {
                case 0:
                    cout << "Let's go to your bag" << endl;
                    demo = 1;
                    openbag(demo);
                    break;

                case 1:
                    buyWeapon();
                    break;

                case 2:
                    cout << "You have chosen to buy an item." << endl;
                    break;

                case 3:
                    cout << "Thank you for visiting the shop!" << endl;
                    cout << "\e[1;1H\e[2J";
                    return;

                default:
                    cout << "Invalid option. Please choose again." << endl;
            }

            cout << "\e[1;1H\e[2J";
        } while (choice != 3);
    }
}
