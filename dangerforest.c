#include "game_functions.h"
void dangerforest (int &eventcount)
{
	eventcount++;
	while (int keepevent=true) {
		printf ("HP: %d\n", HP); sleep(1);
		puts ("You are walking through the forest and hear something is roaring"); sleep(2);
		puts ("You wonder what was that"); sleep(2);
		printf ("0. Open bag\n1. Go hide\n2. leave the area\n3. Seek the sound\nYou decide to ");
		int option;
		scanf ("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\n", HP); sleep(1);
		if (option==1) {
			puts ("You think go hide some where is better"); sleep(2);
			puts ("You hide behind a tree surrounded by bushes"); sleep(2);
			int temp=rand()%10;
			if (temp==0) {
				puts ("You hear something breathes behind you"); sleep(2);
				puts ("It is a wolf"); sleep(2);
				puts ("It sniffed your trace and came"); sleep(5);
				printf ("\e[1;1H\e[2J");
				wolf (HP);
			} else if (temp<3) {
				puts ("Seem that dangerous thing left"); sleep(2);
				puts ("You go out and continue walking");
			} else if (temp<6) {
				puts ("You move slowly backward"); sleep(2);
				puts ("You step on a beartrap"); sleep(2);
				puts ("Dang it"); sleep(2);
				temp=rand()%5+5;
				printf ("-%d HP\n", temp); sleep(2); HP-=temp; if (HP<=0) { HP=0; break;}
				puts ("You open the trap and leave");
			} else {
				puts ("A snake crawls to your place"); sleep(5);
				printf ("\e[1;1H\e[2J");
				snake (HP);
			}
		}
		if (option==2) {
			puts ("You try not to make any noise while leaving this place"); sleep(2);
			int temp=rand()%10;
			if (temp==0) {
				puts ("You step on a beartrap"); sleep(2);
				puts ("So bad"); sleep(2);
				temp=rand()%5+5;
				printf ("-%d HP\n", temp); sleep(2); HP-=temp; if (HP<=0) { HP=0; break;}
				puts ("You open the trap and leave");
			} else if (temp<5) {
				puts ("You step on a dry branch"); sleep(2);
				puts ("So quiet..."); sleep(2);
				puts ("Something roars"); sleep(2);
				puts ("A bear runs toward you"); sleep(5);
				printf ("\e[1;1H\e[2J");
				bear (HP);
			} else puts ("You leave the area successfully");
		}
		if (option==3) {
			puts ("You seek for the thing making that sound"); sleep(2);
			puts ("You are walking"); sleep(2);
			int temp=rand()%20;
			if (temp<3) {
				puts ("You only see a blood trace ahead"); sleep(2);
				puts ("You follow it until no more trace"); sleep(2);
				puts ("Cant do anything"); sleep(2);
				puts ("You continue your way");
			} else if (temp<6) {
				puts ("You see a dead human body"); sleep(2);
				puts ("Such a bad omen man"); sleep(2);
				temp=rand()%6+13;
				printf ("You examined the body and found %d coins\n", temp); sleep(2);
				printf ("+%d coin", temp); coin+=temp;
			} else if (temp<14) {
				puts ("You see a dead dear"); sleep(2);
				temp=rand()%2+2;
				puts ("Cruel scene and you cut some meat from it"); sleep(2);
				printf ("+%d raw meat", temp); bag[1][5]+=temp;
			} else {
				puts ("You see a bear"); sleep(2);
				puts ("It turns around and roars at you"); sleep(5);
				printf ("\e[1;1H\e[2J");
				bear (HP);
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