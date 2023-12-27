#include "game_functions.h"


using namespace std;

void river(int &eventcount) {
    int blockrepeat[7] = {0}, locate = 0;

    while (eventcount < 6) {
        int temp = rand() % 7;

        if (blockrepeat[0] == temp || blockrepeat[1] == temp || blockrepeat[2] == temp || blockrepeat[3] == temp ||
            blockrepeat[4] == temp || blockrepeat[5] == temp || blockrepeat[6] == temp)
            continue;

        blockrepeat[locate] = temp;
        locate++;

        if (temp == 1 || temp == 2 || temp == 3 || temp == 4 || temp == 5 || temp == 6) {
            merchant(eventcount);
        }

        if (HP == 0) {
            break;
        }
    }
}
