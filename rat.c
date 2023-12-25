#include "game_functions.h"

void rat(int &HP)			
{
	int ratHP=18;
	while (ratHP>0) {
		printf ("HP: %d\t\t\tRat HP: %d\n", HP, ratHP); sleep(1);
		printf ("0. Open bag\n1. Attack\nLet's ");
		int option; scanf ("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tRat HP: %d\n", HP, ratHP); sleep(1);
		if (option==1) {
			int temp=rand()%20;
			if (temp==0) puts ("The rat is small so you can not hit it accurately");
				else {
					temp=rand()%5+8;
					printf ("You land a hit with %d damage on the rat", temp); ratHP-=temp;
					if (ratHP<=0) break;
				}
			sleep(5); printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tRat HP: %d\n", HP, ratHP); sleep(1);
			temp=rand()%50;
			if (temp==0) puts ("The rat jump to bite you but you block it");
				else {
					temp=rand()%2+1;
					puts ("The rat bites you"); sleep(2);
					printf ("-%d HP\n", temp); HP-=temp; if (HP<=0) {sleep(2); HP=0; break;}
					temp=rand()%2;
					if (temp==0) {
						sleep(2);
						puts("It quickly bite you again"); sleep(2);
						temp=rand()%2+1;
						printf ("-%d HP\n", temp); HP-=temp; if (HP<=0) {sleep(2); HP=0; break;}
					}
				}
			sleep(5); printf ("\e[1;1H\e[2J");
		}
		if (option==0) {printf ("\e[1;1H\e[2J"); openbag(ratHP);}
	}
	if (ratHP<=0) {
		sleep(5); printf ("\e[1;1H\e[2J");
		printf ("HP: %d\n", HP); sleep(1);
		puts ("You kill the rat"); sleep(2);
		int temp=rand()%2+2;
		puts ("You got"); sleep(2); printf ("+%d coins\n", temp); coin+=temp;
		temp=rand()%2;
		if (temp==0) {sleep(2); puts("This rat was big enough for you to take its meat"); sleep(2); puts("+1 raw meat"); bag[1][5]++;}
	}
}
