#include "game_functions.h"

void bat(int &HP)			
{
	int batHP=23;
	while (batHP>0) {
		printf ("HP: %d\t\t\tBat HP: %d\n", HP, batHP); sleep(1);
		printf ("0. Open bag\n1. Attack\nLet's ");
		int option; scanf ("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tBat HP: %d\n", HP, batHP); sleep(1);
		if (option==1) {
			int temp=rand()%20;
			if (temp==0) puts ("You slash the bat but it flys up");
				else {
					temp=rand()%5+8;
					printf ("You stab the bat with %d damage", temp); batHP-=temp;
					if (batHP<=0) break;
				}
			sleep(5); printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tBat HP: %d\n", HP, batHP); sleep(1);
			temp=rand()%20;
			if (temp==0) puts ("The bat flys downward to you and open its mouth to bite but you block its mouth with your sword");
				else {
					temp=rand()%2+2;
					puts ("The bat bites you"); sleep(2);
					printf ("-%d HP\n", temp); HP-=temp; if (HP<=0) {sleep(2); HP=0; break;}
				}
			sleep(5); printf ("\e[1;1H\e[2J");
		}
		if (option==0) {printf ("\e[1;1H\e[2J"); openbag(batHP);}
	}
	if (batHP<=0) {
		sleep(5); printf ("\e[1;1H\e[2J");
		printf ("HP: %d\n", HP); sleep(1);
		puts ("You kill the bat"); sleep(2);
		int temp=rand()%2+2;
		puts ("You got"); sleep(2); printf ("+%d coins\n", temp); sleep(2); coin+=temp;
		puts ("An apple and a berry fall off the bat body"); sleep(2);
		puts ("+1 apple"); bag[1][0]++;
		puts ("+1 berry"); bag[1][1]++;
		temp=rand()%10;
		if (temp<4) {sleep(2); puts ("A bat hears its friend scream"); sleep(2); puts ("it comes to revenge"); sleep(5); printf ("\e[1;1H\e[2J"); bat(HP);}
	}
}
