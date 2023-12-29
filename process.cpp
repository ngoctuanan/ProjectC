#include "game_functions.h"

using namespace std;

void process(int &HP) {
    while (HP > 0) {
        dayloop(daycount);
    }

    if (HP == 0) {
        sleep(3);
        cout << "\e[1;1H\e[2J";
        cout << "Game over\nYou survived " << daycount << " days\n";
        cout << "\t1. Start a new life\n";
        cout << "\t2. Exit\nYou want to ";

        int option;
        cin >> option;

        cout << "\e[1;1H\e[2J";

        if (option == 1) {
            HP = 100;
            daycount = 0;
            coin = 0;

            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 100; j++)
                    bag[i][j] = 0;

            bag[0][0] = 1;
            process(HP);
        }

        if (option == 2) {
            cout << "Thanks for playing" << endl;
        }
    }
}
