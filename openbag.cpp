#include "game_functions.h"

using namespace std;

void openbag(int &enemyHP) {
    while (bool keepbagopen = true) {
        cout << "HP: " << HP << "\t\t\tCoin: " << coin << endl;
        cout << "0. Nothing\n1. Equipment\n2. Food\n3. Material\n4. Goods\nMaybe open the pocket of ";
        
        int option;
        cin >> option;

        cout << "\e[1;1H\e[2J";

        switch (option) {
            case 1:
                equipment();
                break;

            case 2:
                food();
                break;

            case 3:
                material();
                break;

            case 4:
                goods(enemyHP);
                break;

            case 0:
                cout << "HP: " << HP << "\t\t\tCoin: " << coin << endl;
                cout << "0. Confirm\n1. Wait\nClose bag?\n";

                cin >> option;

                cout << "\e[1;1H\e[2J";

                if (option == 0)
                    break;

                break;

            default:
                break;
        }

        if (HP == 0)
            break;
    }

    cout << "\e[1;1H\e[2J";
    sleep(1);
}
