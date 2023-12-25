#include "game_functions.h"
void startday(int &eventcount)
{
	while (bool keepday=true){
	printf ("HP: %d\n", HP); sleep(1);
	printf ("Day %d\n", daycount); sleep(1);
	printf ("Where do you want to go?\n0. Open bag\n1. Go to the river bank\n2. Go explore the forest\nLet's ");
	int option;
	scanf ("%d", &option);
	printf ("\e[1;1H\e[2J");
	if (option==1) river(eventcount);
	if (option==2) forest(eventcount);
	if (option==0) {int blockusegoods=0; openbag(blockusegoods);}
		else break;
	}
}