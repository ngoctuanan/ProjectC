#include "game_functions.h"
void food()
{
	bool keeppocketopen=true;
	while (keeppocketopen) {
		printf ("HP: %d\t\t\tCoin: %d\n", HP, coin);
		int count=0, *temp[]={0};
			if (bag[1][0]) {printf ("%d. %5s: %d          ", count, "Apple", bag[1][0]); temp[count]=&bag[1][0]; count++;}
			if (bag[1][1]) {printf ("%d. %5s: %d          ", count, "Berry", bag[1][1]); temp[count]=&bag[1][1]; count++;}
			if (bag[1][2]) {printf ("%d. %10s: %d     ", count, "Small fish", bag[1][2]); temp[count]=&bag[1][2]; count++;}
			if (bag[1][3]) {printf ("%d. %11s: %d    ", count, "Medium fish", bag[1][3]); temp[count]=&bag[1][3]; count++;}
			if (bag[1][4]) {printf ("%d. %10s: %d     ", count, "Large fish", bag[1][4]); temp[count]=&bag[1][4]; count++;} 
			if (bag[1][5]) {printf ("%d. %8s: %d     ", count, "Raw meat", bag[1][5]); temp[count]=&bag[1][5]; count++;} puts("");
			if (bag[1][6]) {printf ("%d. %6s: %d         ", count, "Banana", bag[1][6]); temp[count]=&bag[1][6]; count++;}
			if (bag[1][8]) {printf ("%d. %8s: %d       ", count, "Mushroom", bag[1][8]); temp[count]=&bag[1][8]; count++;}
			if (bag[1][9]) {printf ("%d. %3s: %d            ", count, "Egg", bag[1][9]); temp[count]=&bag[1][9]; count++;}
		printf("\n\n");
		printf ("%d. Nothing\nYou want to consume ", count);
		int option;
		scanf ("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tCoin: %d\n", HP, coin); sleep(1);
		if (temp[option]==&bag[1][0]) {
			bag[1][0]--;
			int consume=rand()%10;
			if (consume==0) {puts("The apple has a worm inside"); sleep(2); puts("-3 HP"); sleep(2); printf ("\e[1;1H\e[2J"); HP-=3; if (HP<0) {HP=0; break;}}
			else { consume=rand()%3+5; puts("Juicy apple"); sleep(2); printf("+%d HP", consume); sleep(2); printf ("\e[1;1H\e[2J"); HP+=consume; if (HP>100) HP=100;}
		}
		if (temp[option]==&bag[1][1]) {
			bag[1][1]--;
			int consume=rand()%10;
			if (consume==0) {puts("The berry was rotten"); sleep(2); puts("-3 HP"); sleep(2); printf ("\e[1;1H\e[2J"); HP-=3; if (HP<0) {HP=0; break;}}
			else { consume=rand()%2+2; puts("Fresh berry"); sleep(2); printf("+%d HP", consume); sleep(2); printf ("\e[1;1H\e[2J"); HP+=consume; if (HP>100) HP=100;}
		}
		if (temp[option]==&bag[1][2]) {
			bag[1][2]--;
			int consume=rand()%4;
			if (consume==0) {puts("You get poison from eating raw food"); sleep(2); puts("-7 HP"); sleep(2); printf ("\e[1;1H\e[2J"); HP-=7; if (HP<0) {HP=0; break;}}
			else {puts("Small fish does not suply much vitamins"); sleep(2); puts("It is even raw"); sleep(2); puts("+3 HP"); sleep(2); printf ("\e[1;1H\e[2J"); HP+=3; if (HP>100) HP=100;}
		}
		if (temp[option]==&bag[1][3]) {
			bag[1][3]--;
			int consume=rand()%4;
			if (consume==0) {puts("You get poison from eating raw food"); sleep(2); puts("-7 HP"); sleep(2); printf ("\e[1;1H\e[2J"); HP-=7; if (HP<0) {HP=0; break;}}
			else {consume=rand()%2+4; puts("Raw medium fish gives fine taste"); sleep(2); printf("+%d HP", consume); sleep(2); printf ("\e[1;1H\e[2J"); HP+=consume; if (HP>100) HP=100;}
		}
		if (temp[option]==&bag[1][4]) {
			bag[1][4]--;
			int consume=rand()%4;
			if (consume==0) {puts("You get poison from eating raw food"); sleep(2); puts("-7 HP"); sleep(2); printf ("\e[1;1H\e[2J"); HP-=7; if (HP<0) {HP=0; break;}}
			else {puts("Large fish is delicious"); sleep(2); puts("But is raw"); sleep(2); puts("+6 HP"); sleep(2); printf ("\e[1;1H\e[2J"); HP+=6; if (HP>100) HP=100;}
		}
		if (temp[option]==&bag[1][5]) {
			bag[1][5]--;
			int consume=rand()%4;
			if (consume==0) {puts("You get poison from eating raw food"); sleep(2); puts("-7 HP"); sleep(2); printf ("\e[1;1H\e[2J"); HP-=7; if (HP<0) {HP=0; break;}}
			else {puts("Raw meat does not suply much vitamins"); sleep(2); puts("+4 HP"); sleep(2); printf ("\e[1;1H\e[2J"); HP+=4; if (HP>100) HP=100;}
		}
		if (temp[option]==&bag[1][6]) {
			bag[1][6]--;
			int consume=rand()%10;
			if (consume==0) {puts("The banana was out of date"); sleep(2); puts("-3 HP"); sleep(2); printf ("\e[1;1H\e[2J"); HP-=3; if (HP<0) {HP=0; break;}}
			else {consume=rand()%2+3; puts("Yum banana"); sleep(2); printf("+%d HP", consume); sleep(2); printf ("\e[1;1H\e[2J"); HP+=consume; if (HP>100) HP=100;}
		}
		if (temp[option]==&bag[1][8]) {
			bag[1][8]--;
			int consume=rand()%4;
			if (consume==0) {puts("A poisonous mushroom grow on the mushroom you ate"); sleep(2); puts("-7 HP"); sleep(2); printf ("\e[1;1H\e[2J"); HP-=7; if (HP<0) {HP=0; break;}}
			else { consume=rand()%3+2; puts("Wild mushroom supply you some health"); sleep(2); printf("+%d HP", consume); sleep(2); printf ("\e[1;1H\e[2J"); HP+=consume; if (HP>100) HP=100;}
		}
		if (temp[option]==&bag[1][9]) {
			bag[1][9]--;
			puts ("You just ate an uncooked egg?"); sleep(2); puts ("So boid"); sleep(2); puts ("+4 HP"); sleep(2); HP+=4; printf ("\e[1;1H\e[2J");
			if (HP>100) HP=100;
		}
		if (option==count) {
			printf ("0. Confirm\n1. Ehh...\nClose pocket?\n");
			scanf ("%d", &option);
			printf ("\e[1;1H\e[2J");
			if (option==0) break;
		}
	}
}
