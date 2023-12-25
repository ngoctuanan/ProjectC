#include "game_functions.h"
void fruitbasket(int &eventcount)
{
	eventcount++;
	while (bool keepevent=true) {
		printf ("HP: %d\n", HP); sleep(1);
		puts ("You see a basket left beside the river"); sleep(2);
		puts ("You come close and see that is the basket of fruits"); sleep(2);
		printf ("0. Open bag\n1. Take all fruit\n2. Just take an apple\nYou decide to ");
		int option; scanf("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\n", HP); sleep(1);
		if (option==1) {
			puts ("You pick up the basket"); sleep(2);
			int temp=rand()%10;
			if (temp<3) {
				puts ("A monkey appears and steal the basket from you"); sleep(2);
				puts ("You cant let it have the basket"); sleep(5);
				printf ("\e[1;1H\e[2J");
				monkey (HP);
				if (HP==0) break; else {
					sleep(5); printf ("\e[1;1H\e[2J");
					printf ("HP: %d\n", HP); sleep(1);
					puts ("You take the basket back from the monkey"); sleep(2);
				}
			}
			puts ("From the basket you get"); sleep(2);
			temp=rand()%2+2;
			printf ("+%d apples\n", temp); bag[1][0]+=temp;
			puts ("+1 banana"); bag[1][6]++;
			temp=rand()%3+2;
			printf ("+%d berries", temp); bag[1][1]+=temp;
		}
		if (option==2) {
			puts ("You take a look"); sleep(2);
			puts ("You choose the best apple and take a bite"); sleep(2);
			int temp=rand()%4+7;
			printf ("+%d HP", temp); HP+=temp; if (HP>100) HP=100;
			temp=rand()%5;
			if (temp==0) {
				sleep(2);
				puts ("\nThe owner of the basket comes back right the time to see you bite their fruit"); sleep(2);
				puts ("She wants you to pay for that apple"); sleep(2);
				if (coin>=5) {puts ("-5 coins"); coin-=5; sleep(2); puts("The woman takes the basket and leaves");}
					else if (coin==0) {puts ("You do not have any coin"); sleep(2); puts ("The woman is angry"); sleep(2); puts("she takes the basket and leaves");}
						else {printf ("-%d coin"); if (coin!=1) printf("s"); coin=0; sleep(2); puts (""); puts("The woman takes the basket and leaves");}
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