#include "game_functions.h"

void wolf(int &HP)
{
	int wolfHP=55;
	while (wolfHP>0) {
		printf ("HP: %d\t\t\tWolf HP: %d\n", HP, wolfHP); sleep(1);
		printf ("0. Open bag\n1. Attack\nLet's ");
		int option; scanf ("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tWolf HP: %d\n", HP, wolfHP); sleep(1);
		if (option==1) {
			int temp=rand()%20;
			if (temp==0) puts ("You stab the wolf but it jumps back");
				else {
					temp=rand()%5+8;
					printf ("You kick the sword hilt and it stabs the wolf with %d damage\n", temp); wolfHP-=temp; sleep(2);
					puts ("You avoid the wolf and take the sword back");
					if (wolfHP<=0) break;
				}
			sleep(5); printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tWolf HP: %d\n", HP, wolfHP); sleep(1);
			temp=rand()%25;
			if (temp<2) puts ("The wolf bite you but you dodge and it bites the air surrounding you instead");
				else {
					temp=rand()%2+9;
					puts ("The wolf damages you with its claws"); sleep(2);
					printf ("-%d HP\n", temp); HP-=temp; if (HP<=0) {sleep(2); HP=0; break;}
					temp=rand()%10;
					if (temp==0) {
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
		if (option==0) {printf ("\e[1;1H\e[2J"); openbag(wolfHP);}
	}
	if (wolfHP<=0) {
		sleep(5); printf ("\e[1;1H\e[2J");
		printf ("HP: %d\n", HP); sleep(1);
		puts ("You defeat the wolf"); sleep(2);
		puts ("That was..."); sleep(2);
		int temp=rand()%2+9;
		puts ("You got"); sleep(2); printf ("+%d coins\n", temp); sleep(2); coin+=temp;
		puts ("You slash some meat from the wolf dead body"); sleep(2);
		printf ("+2 raw meat", temp); bag[1][5]+=2;
	}
}