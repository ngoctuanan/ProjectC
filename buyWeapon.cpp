#include "game_functions.h"


using namespace std;

void buyWeapon()
{
    int choice;
    do
    {
        cout << "You have chosen to buy a weapon." << endl;
        cout << "Your coin: " << coin << endl;
        cout << "1. LongSword: (15 coins to purchase, and it deals 5 damage.)" << endl;
        cout << "2. Bow: (10 coins to purchase, and it grants 4 damage.)" << endl;
        cout << "3. The dagger (20 coins to buy, deals 7 damage, and has an additional attack effect with a 15% chance.)" << endl;
        cout << "0. Nothing" << endl;
        cin >> choice;
        cout << "\e[1;1H\e[2J";

        switch (choice)
        {
        case 1:
            if (coin >= 15)
            {
                dame += 5;
                coin -= 15;
                cout << "You have purchased a longsword, and it deals 5 damage. Your total damage is now: " << dame << endl;
            }
            else
            {
                cout << "I'm sorry, but you don't have enough money to complete the transaction." << endl;
            }
            break;
        case 2:
            if (coin >= 10)
            {
                dame += 4;
                coin -= 10;
                cout << "You choose to buy a wooden bow. It deals 4 damage, and your current total damage is " << dame << endl;
            }
            else
            {
                cout << "I'm sorry, but you don't have enough money to complete the transaction." << endl;
            }
            break;
        case 3:
            if (coin >= 20)
            {
                dame += 7;
                coin -= 20;
                cout << "You choose to buy the dagger. It deals 7 damage, and your current total damage is " << dame << endl;
            }
            else
            {
                cout << "I'm sorry, but you don't have enough money to complete the transaction." << endl;
            }
            break;
        case 0:
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 0);
}

