#include "game_functions.h"


using namespace std;

void startday(int &eventcount) {
    while (true) {
        cout << "HP: " << HP << endl;
        sleep(1);
        cout << "Day " << daycount << endl;
        sleep(1);
        cout << "Where do you want to go?" << endl;
        cout << "0. Open bag\n1. Go to the river bank\n2. Go explore the forest\nLet's ";

        int option;
        cin >> option;

        cout << "\e[1;1H\e[2J";

        if (option == 1) {
            river(eventcount);
        if (option == 2) {
            forest(eventcount);
        if (option == 0) {
            int blockusegoods = 0;
            openbag(blockusegoods);
        } else break;
    }
}
