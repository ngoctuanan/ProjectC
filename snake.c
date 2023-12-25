#include "game_functions.h"
void snake (int &HP)
{
	int snakeHP=30;
	while (snake>0) {
		printf ("HP: %d\t\t\tSnake HP: %d\n", HP, snakeHP); sleep(1);
		printf ("0. Open bag\n1. Attack\nLet's ");
		int option; scanf("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tSnake HP: %d\n", HP, snakeHP); sleep(1);
		if (option==1) {
			int temp=rand()%20;
			if (temp==0) puts ("The snake dodged and you hit the ground");
				else {
					temp=rand()%5+8;
					printf ("You land a hit with %d damage on the snake", temp); snakeHP-=temp;
					if (snakeHP<=0) break;
				}
			sleep(5); printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tSnake HP: %d\n", HP, snakeHP);
			temp=rand()%100;
			if (temp<7) puts ("The snake attacks with poisonous ball but you dodge");
				else {
					temp=rand()%3+3;
					puts ("The snake throws up poisonous ball on you"); sleep(2);
					printf ("-%d HP\n", temp); HP-=temp; if (HP<=0) {sleep(2); HP=0; break;}
					temp=rand()%10;
					if (temp<3) {
						sleep(1);
						printf ("Wait"); sleep(1); printf ("."); sleep(1); printf ("."); sleep(1); printf ("."); sleep(1); puts("");
						puts ("You get effected by poison"); sleep(2);
						printf ("-7 HP"); HP-=7; if (HP<=0) {sleep(2); HP=0; break;}
					}
				}
			sleep(5); printf ("\e[1;1H\e[2J");
		}
		if (option==0) {printf ("\e[1;1H\e[2J"); openbag(snakeHP);}
	}
	if (snakeHP<=0){
		sleep(5); printf ("\e[1;1H\e[2J");
		printf ("HP: %d\n", HP); sleep(1);
		puts ("The snake dies and you get");
		int temp=rand()%4+3;
		printf ("+%d coins\n", temp); coin+=temp;
		temp=rand()%10;
		if (temp!=0) {printf ("+1 raw meat"); bag[1][5]++;}
	}
}
