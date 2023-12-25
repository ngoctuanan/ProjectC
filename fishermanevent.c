#include "game_functions.h"

void fishermanevent(int &eventcount)
{
	eventcount++;
	while (bool keepevent=true) {
	printf ("HP: %d\n", HP); sleep(1);
	puts ("Along the river"); sleep(2);
	puts ("You see someone fishing"); sleep(2);
	printf ("0. Open bag\n1. Come close\n2. Ignore him\nYou decide to ");
	int option; scanf("%d", &option);
	printf ("\e[1;1H\e[2J"); printf ("HP: %d\n", HP); sleep(1);
	if (option==1) {
		puts ("For curiousity you walk toward him"); sleep(2);
		int temp=rand()%20;
		if (temp<2) {
			puts ("You say hi and he wave his hand toward you"); sleep(2);
			puts ("He grab the knife on his waist with the other hand and rob you"); sleep(5);
			printf ("\e[1;1H\e[2J");
			thief (HP);
		} else if (temp<8) {
			puts ("He was lucky today and caught a lot of fishs"); sleep(2);
			puts ("He gives you one"); sleep(2);
			temp=rand()%10;
			if (temp>1) {puts ("+1 small fish"); bag[1][2]++;}
				else {puts ("+1 medium fish"); bag[1][3]++;}
		} else {
			puts ("He offers to buy some fishs from you"); sleep(2);
			if (bag[1][2]>0||bag[1][3]>0||bag[1][4]>0) {
				sleep(3);
				while (bag[1][2]>0||bag[1][3]>0||bag[1][4]>0) {
					printf ("\e[1;1H\e[2J"); printf ("HP: %d\n", HP); sleep(1);
					int count=0, *sell[]={0};
					while (count<3) {
						if (bag[1][2]) {printf ("%d. Small fish=3 coins \tyou have %d     ", count, bag[1][2]); sell[count]=&bag[1][2]; count++;}
						if (bag[1][3]) {printf ("%d. Medium fish=5 coins\tyou have %d    ", count, bag[1][3]); sell[count]=&bag[1][3]; count++;}
						if (bag[1][4]) {printf ("%d. Large fish=7 coins \tyou have %d     ", count, bag[1][4]); sell[count]=&bag[1][4]; count++;}
						break;
					}
					puts ("");
					printf ("%d. Nothing\nYou want to sell ", count);
					int interoption;
					scanf ("%d", &interoption);
					printf ("\e[1;1H\e[2J"); printf ("HP: %d\n", HP); sleep(1);
					if (sell[interoption]==&bag[1][2]) {puts("-1 small fish\n+3 coins"); sleep(2); bag[1][2]--; coin+=3;}
					if (sell[interoption]==&bag[1][3]) {puts("-1 medium fish\n+5 coins"); sleep(2); bag[1][3]--; coin+=5;}
					if (sell[interoption]==&bag[1][4]) {puts("-1 large fish\n+7 coins"); sleep(2); bag[1][4]--; coin+=7;}
					if (interoption==count) {
						printf ("0. Confirm\n1. Maybe no\nLeave?\n");
						scanf ("%d", &interoption);
						printf ("\e[1;1H\e[2J"); printf ("HP: %d\n", HP); sleep(1);
						if (interoption==0) break;
					}
				}
				if (bag[1][2]==0&&bag[1][3]==0&&bag[1][4]==0) {puts ("You have no more fish to sell"); sleep(2);}
			} else {puts ("You have no fish to sell"); sleep(2); puts("He understood"); sleep(2);}
			puts ("You leave");
		  }
		}
	if (option==2) {
		puts ("You ignore that person and continue walking"); sleep(2);
		int temp=rand()%10;
		if (temp<3) {
			puts ("That person does not let you go"); sleep(2);
			puts ("He grabs your hand and point the knife at you"); sleep(2);
			puts ("He seem to be a thief"); sleep(5);
			printf ("\e[1;1H\e[2J");
			thief (HP);
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