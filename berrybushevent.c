#include "game_functions.h"

void berrybushevent(int &eventcount)
{
	eventcount++;
	while (bool keepevent=true) {
	printf ("HP: %d\n", HP); sleep(1);
	printf ("You are walking and berry bushes along the river catch your sight\n"); sleep(1);
	printf ("0. Open bag\n1. Harvest some berries\n2. Ignore it\n3. Star at the bushes\nYou decide to ");
	int option; scanf("%d", &option);
	printf ("\e[1;1H\e[2J"); printf ("HP: %d\n", HP); sleep(1);
	if (option==1) {
		int temp=rand()%5+3;
		puts ("You walk toward and pick some berries"); sleep(2);
		printf ("+%d berries\n", temp); bag[1][1]+=temp;
		temp=rand()%10;
		if (temp<3) {
			sleep(1);
			printf ("Wait"); sleep(1); printf ("."); sleep(1); printf ("."); sleep(1); printf ("."); sleep(1); puts("");
			puts ("You step on ants hill when you are about to leave"); sleep(2);
			puts ("It is your fault for being clumsy"); sleep(2);
			puts ("Now they climb up and bite you"); sleep(2);
			temp=rand()%3+1;
			printf ("-%d HP", temp); HP-=temp; if (HP<0) HP=0;
		}
	}
	if (option==2) {
		int temp=rand()%10;
		if (temp>2) puts ("Although how delicious these berries look like, you walk away...");
		else {
			puts ("You turn your head away and suddenly a snake jumps out from the bushes and attacks you");
			sleep(5);
			printf ("\e[1;1H\e[2J");
			snake (HP);
		}
	}
	if (option==3) {
		int temp=rand()%10;
		if (temp<7) {puts ("You just pick a berry and leave"); sleep(2); puts ("+1 berry"); bag[1][1]++;}
		else {
			temp=rand()%3+1;
			if (temp==1) {puts ("You notice something shiny thought the bushes"); sleep(2); puts ("It is a coin"); sleep(2); puts ("+1 coin"); coin++;}
			else {puts ("You notice something shiny thought the bushes"); sleep(2); puts ("they are coins"); sleep(2); printf("+%d coin", temp); coin+=temp;}
		}
	}
	if (option==0) {printf ("\e[1;1H\e[2J"); int blockusegoods=0; openbag(blockusegoods);}
		else {
			sleep(5);
			printf ("\e[1;1H\e[2J");
			break;
		}
	}
}