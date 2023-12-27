#include "game_functions.h"


using namespace std;

void material() {
    while (bool keeppocketopen = true) {
        cout << "HP: " << HP << "\t\t\tCoin: " << coin << endl;

        int count = 0;
        while (count < 2) {
            if (count % 5 == 0)
                cout << endl;

            if (bag[2][0]) {
                cout << sleep(4) << "Clay: " << bag[2][0] << "      ";
                count++;
            }

            if (bag[2][1]) {
                cout << sleep(5) << "Stone: " << bag[2][1] << "     ";
                count++;
            }

            break;
        }

        cout << "\n\n";
        cout << "0. Confirm\n1. Ehh...\nClose pocket?\n";

        int option;
        cin >> option;

        cout << "\e[1;1H\e[2J";

        if (option == 0)
            break;
    }
}
