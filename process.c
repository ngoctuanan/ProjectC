#include "game_functions.h"
void process(int &HP)
{
	while (HP>0) {
		dayloop (daycount);
 	}
	if (HP==0) {
		sleep(3);
		printf ("\e[1;1H\e[2J");
		printf ("Game over\nYou survived %d days\n\t1. Start a new life\n\t2. Exit\nYou want to ", daycount);
		int option;
		scanf ("%d", &option);
		printf ("\e[1;1H\e[2J");
		if (option==1) {
			HP=100; daycount=0; coin=0;
			for (int i=0; i<4; i++)
				for (int j=0; j<10; j++) bag[i][j]=0;
			bag[0][0]=1;
			process (HP);
		}
		if (option==2) printf ("Thanks for playing");
	}
}