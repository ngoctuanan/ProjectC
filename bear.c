#include "game_functions.h"
void bear(int &HP)
{
	int bearHP=75;
	while (bearHP>0) {
		printf ("HP: %d\t\t\tBear HP: %d\n", HP, bearHP); sleep(1);
		printf ("0. Open bag\n1. Attack\nLet's ");
		int option; scanf ("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tBear HP: %d\n", HP, bearHP); sleep(1);
		if (option==1) {
			int temp=rand()%20;
			if (temp==0) puts ("You stab the bear but it blocks your sword");
				else {
					temp=rand()%5+8;
					printf ("You slash the bear with %d damage", temp); bearHP-=temp;
					if (bearHP<=0) break;
				}
			sleep(5); printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tBear HP: %d\n", HP, bearHP); sleep(1);
			temp=rand()%50;
			if (temp<9) puts ("You dodge when the bear run toward you");
				else {
					temp=rand()%3+10;
					puts ("The bear jumps up and lands behind you to bite"); sleep(2);
					printf ("-%d HP\n", temp); HP-=temp; if (HP<=0) {sleep(2); HP=0; break;}
					temp=rand()%5;
					if (temp<2) {
						sleep(2);
						puts ("That was a deep bite"); sleep(2);
						puts ("The wound starts bleeding"); sleep(2);
						puts ("-5 HP"); HP-=5; if (HP<=0) {sleep(2); HP=0; break;}
						temp=rand()%4;
						if (temp<3) {sleep(2); puts ("It keeps bleeding"); sleep(2); puts ("-5 HP"); HP-=5; if (HP<=0) {sleep(2); HP=0; break;}}
					}
				}
			sleep(5); printf ("\e[1;1H\e[2J");
		}
		if (option==0) {printf ("\e[1;1H\e[2J"); openbag(bearHP);}
	}
	if (bearHP<=0) {
		sleep(5); printf ("\e[1;1H\e[2J");
		printf ("HP: %d\n", HP); sleep(1);
		puts ("You finally defeat that bear"); sleep(2);
		int temp=rand()%3+13;
		puts ("You got"); sleep(2); printf ("+%d coins\n", temp); sleep(2); coin+=temp;
		temp=rand()%2+3;
		puts ("You stab the bear dead body for its meat");
		printf ("+%d raw meat", temp); bag[1][5]+=temp;
	}
}