#include "game_functions.h"
void thief(int &HP)
{
	int thiefHP=50, thiefbag=0;
	while (thiefHP>0) {
		printf ("HP: %d\t\t\tThief HP: %d\n", HP, thiefHP); sleep(1);
		printf ("0. Open bag\n1. Attack\nLet's ");
		int option; scanf("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tThief HP: %d\n", HP, thiefHP); sleep(1);
		if (option==1) {
			int temp=rand()%20;
			if (temp==0) puts ("The thief dodged and you land your attack in the air");
				else {
					temp=rand()%5+8;
					printf ("You land a hit with %d damage on him", temp); thiefHP-=temp;
					if (thiefHP<=0) break;
				}
			sleep(5); printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tThief HP: %d\n", HP, thiefHP);
			temp=rand()%20;
			if (temp==0) {puts ("Thief guess he cannot defeat you"); sleep(2); puts ("He runs away"); sleep(2); break;}
				else {
					temp=rand()%10;
					if (temp==0) {
					puts ("You step back and his knife just almost touch your face"); sleep(2);
					puts ("He misses");
					} else {
						temp=rand()%3+5;
						puts ("He slashes you with the knife"); sleep(2);
						puts ("That is hurt"); sleep(2);
						printf ("-%d HP\n", temp); sleep(2); HP-=temp; if (HP<=0) {HP=0; break;}
						if (coin==1) {puts ("He stole a coin from you before you realised"); sleep(2); puts ("-1 coin"); coin--; thiefbag++;}
						if (coin>1) {
							temp=rand()%2+1;
							if (temp==1) {puts ("He stole a coin from you before you realised"); sleep(2); puts ("-1 coin"); coin--; thiefbag++;}
							else {puts ("He stole 2 coins from you before you realised"); sleep(2); puts ("-2 coins"); coin-=2; thiefbag+=2;}
						}
					}
				}
			sleep(5);
			printf ("\e[1;1H\e[2J");
		}
		if (option==0) {printf ("\e[1;1H\e[2J"); openbag(thiefHP);}
	}
	if (thiefHP<=0) {
		sleep(5); printf ("\e[1;1H\e[2J");
		printf ("HP: %d\n", HP); sleep(1);
		puts ("You knock down the thief but you can not kill people"); sleep(2);
		if (thiefbag>0) {
		puts ("You get your coins back from him"); sleep(2);
		if (thiefbag==1) {puts ("+1 coin"); coin++;}
			else {printf ("+%d coins\n", thiefbag); coin+=thiefbag;}
		puts ("And his coins");
		int temp=rand()%6+15;
		printf ("+%d coins\n", temp); coin+=temp;
		} else {
			puts ("You take some coins from him"); sleep(2);
			int temp=rand()%6+15;
			printf ("+%d coins\n", temp); coin+=temp;
		}
	}
}