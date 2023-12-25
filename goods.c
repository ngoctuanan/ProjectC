#include "game_functions.h"
void goods(int &enemyHP)
{
	bool keeppocketopen=true;
	while (keeppocketopen) {
		printf ("HP: %d\t\t\tCoin: %d\n", HP, coin);
		int count=0, *temp[]={0};
		while (count<2) {
			if (count%5==0) puts("");
			if (bag[3][0]) {printf ("%d. %4s: %d         ", count, "Rock", bag[3][0]); temp[count]=&bag[3][0]; count++;}
			if (bag[3][1]) {printf ("%d. %4s: %d         ", count, "Bomb", bag[3][1]); temp[count]=&bag[3][1]; count++;}
			break;
		}
		printf("\n\n");
		if (enemyHP>0) {
			printf ("%d. Nothing\nYou want to use ", count);
			int option, missrate=rand()%20;
			scanf ("%d", &option);
			printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tCoin: %d\n", HP, coin); sleep(1);
			if (temp[option]==&bag[3][0]) bag[3][0]--;
			if (temp[option]==&bag[3][1]) bag[3][1]--;
			if (option!=count) {
				if (missrate==0) {
					printf ("."); sleep(1); printf ("."); sleep(1); printf ("."); sleep(1); puts("");
					puts("As expected"); sleep(2);
					puts("Due to your bad throwing skill"); sleep(2);
					puts("The thing you threw flys over the enemy and lands on a point far away from the enemy..."); sleep(2);
					puts("welp..."); sleep(2);
					printf ("\e[1;1H\e[2J");
				} else {
					if (temp[option]==&bag[3][0])
						{printf("You throw a rock and it hits enemy's head and does 4 damage"); sleep(3); printf ("\e[1;1H\e[2J"); enemyHP-=4; if (enemyHP<0) enemyHP=0;}
					if (temp[option]==&bag[3][1])
						{puts("You throw a bomb beside the enemy"); sleep(2); puts("It explodes and does 18 damage"); sleep(3); printf ("\e[1;1H\e[2J"); enemyHP-=18; if (enemyHP<0) enemyHP=0;}
					printf ("\e[1;1H\e[2J");
			 	 }
			}
			if (option==count) {
				printf ("0. Confirm\n1. Ehh...\nClose pocket?\n");
				scanf ("%d", &option);
				printf ("\e[1;1H\e[2J");
				if (option==0) break;
			}
		} else {
			puts ("0. Confirm\n1. Ehh...\nClose pocket?\n");
			int option;
			scanf ("%d", &option);
			printf ("\e[1;1H\e[2J");
			if (option==0) break;
		  }
	}
}