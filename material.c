#include "game_functions.h"
void material ()
{
	while (bool keeppocketopen=true) {
		printf ("HP: %d\t\t\tCoin: %d\n", HP, coin);
		int count=0;
		while (count<2) {
			if (count%5==0) puts("");
			if (bag[2][0]) {printf ("%4s: %d      ", "Clay", bag[2][0]); count++;}
			if (bag[2][1]) {printf ("%5s: %d     ", "Stone", bag[2][1]); count++;}
			break;
		}
		printf("\n\n");
		puts ("0. Confirm\n1. Ehh...\nClose pocket?\n");
		int option;
		scanf ("%d", &option);
		printf ("\e[1;1H\e[2J");
		if (option==0) break;
	}
}