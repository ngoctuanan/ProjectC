#include "game_functions.h"

void monkey (int &HP)
{
	int monkeyHP=40;
	while (monkeyHP>0) {
		printf ("HP: %d\t\t\tMonkey HP: %d\n", HP, monkeyHP); sleep(1);
		printf ("0. Open bag\n1. Attack\nLet's ");
		int option; scanf ("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tMonkey HP: %d\n", HP, monkeyHP); sleep(1);
		if (option==1) {
			int temp=rand()%20;
			if (temp==0) puts ("You slash the monkey but it misses");
				else {
					temp=rand()%5+8;
					printf ("You land the sword blade on the monkey and do %d damage\n", temp); monkeyHP-=temp; sleep(2);
					if (monkeyHP<=0) break;
				}
			sleep(5); printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tMonkey HP: %d\n", HP, monkeyHP); sleep(1);
			temp=rand()%25;
			if (temp==0) puts ("The monkey punches your blade");
				else {
					temp=rand()%3+7;
					puts ("The monkey punches in your face"); sleep(2);
					printf ("-%d HP\n", temp); HP-=temp; if (HP<=0) {sleep(2); HP=0; break;}
					if (bag[1][0]||bag[1][1]||bag[1][6]) {
						int count=0, *steal[3]={0};
						if (bag[1][0]) {steal[count]=&bag[1][0]; count++;}
						if (bag[1][1]) {steal[count]=&bag[1][1]; count++;}
						if (bag[1][6]) steal[count]=&bag[1][6];
						int eat;
						while (bool keeprandom=true) {
							eat=rand()%3;
							if (steal[eat]=&bag[1][0]) {
								puts ("The monkey steal your apple and eat"); sleep(2);
								puts ("-1 apple"); bag[1][0]--; sleep(2);
								int consume=rand()%10;
								if (consume==0) {puts("The apple has a worm inside"); sleep(2); puts("Monkey -3 HP"); sleep(2); monkeyHP-=3; if (monkeyHP<=0) break;}
								else {consume=rand()%3+5; puts("Juicy apple"); sleep(2); printf("Monkey +%d HP", consume); sleep(2); monkeyHP+=consume; if (monkeyHP>40) HP=40;}
								break;
							} else if (steal[eat]=&bag[1][1]) {
								puts ("The monkey steal your berry and eat"); sleep(2);
								puts ("-1 berry"); bag[1][1]--; sleep(2);
								int consume=rand()%10;
								if (consume==0) {puts("The berry was rotten"); sleep(2); puts("Monkey -3 HP"); sleep(2); monkeyHP-=3; if (monkeyHP<=0) break;}
								else {consume=rand()%2+2; puts("Fresh berry"); sleep(2); printf("Monkey +%d HP", consume); sleep(2); monkeyHP+=consume; if (monkeyHP>40) HP=40;}
								break;
							} else if (steal[eat]=&bag[1][6]) {
								puts ("The monkey steal your banana and eat"); sleep(2);
								puts ("-1 banana"); bag[1][6]--; sleep(2);
								int consume=rand()%10;
								if (consume==0) {puts("The banana was out of date"); sleep(2); puts("Monkey -3 HP"); sleep(2); monkeyHP-=3; if (monkeyHP<=0) break;}
								else {consume=rand()%2+3; puts("Yum banana"); sleep(2); printf("Monkey +%d HP", consume); sleep(2); monkeyHP+=consume; if (monkeyHP>40) HP=40;}
								break;
							}
						}
					}
				}
			sleep(5); printf ("\e[1;1H\e[2J");
		}
		if (option==0) {printf ("\e[1;1H\e[2J"); openbag(monkeyHP);}
	}
	if (monkeyHP<=0) {
		sleep(5); printf ("\e[1;1H\e[2J");
		printf ("HP: %d\n", HP); sleep(1);
		puts ("You defeat the monkey"); sleep(2);
		int temp=rand()%3+3;
		puts ("You got"); sleep(2); printf ("+%d coins\n", temp); sleep(2); coin+=temp;
		puts ("You found some bananas in its dead body"); sleep(2);
		temp=rand()%2+2;
		printf ("+%d bananas", temp); bag[1][6]+=temp;
	}
}