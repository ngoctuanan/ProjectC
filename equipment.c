#include "game_functions.h"
#include <stdbool.h>
void equipment()
{   
	keeppocketopen=true;
	while (keeppocketopen) {
		printf ("HP: %d\t\t\tCoin: %d\n", HP, coin);
		int count=0;
		while (count<1) {
			if (count%5==0) puts("");
			if (bag[0][0]) {printf ("Sword"); count++;}
		}
		printf("\n\n");
		puts ("0. Confirm\n1. Ehh...\nClose pocket? ");
		int option;
		scanf ("%d", &option);
		printf ("\e[1;1H\e[2J");
		if (option==0) break;
	}
}