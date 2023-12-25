#include "game_functions.h"
void openbag (int &enemyHP)
{
	while (bool keepbagopen=true) {
		printf ("HP: %d\t\t\tCoin: %d\n", HP, coin);
		printf ("0. Nothing\n1. Equipment\n2. Food\n3. Material\n4. Goods\nMaybe open the pocket of ");
		int option;
		scanf ("%d", &option);
		printf ("\e[1;1H\e[2J");
		if (option==1) equipment();
		if (option==2) food();
		if (option==3) material();
		if (option==4) goods(enemyHP);
		if (option==0) {
			printf ("HP: %d\t\t\tCoin: %d\n", HP, coin);
			printf ("0. Confirm\n1. Wait\nClose bag?\n");
			scanf ("%d", &option);
			printf ("\e[1;1H\e[2J");
			if (option==0) break;
		}
		if (HP==0) break;
	}
	printf ("\e[1;1H\e[2J"); sleep(1);
}