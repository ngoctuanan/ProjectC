#include "game_functions.h"
void gianttree(int &eventcount)
{
	eventcount++;
	while (int keepevent=true) {
		printf ("HP: %d\n", HP); sleep(1);
		puts ("You across the forest and stop at a giant tree in front"); sleep(2);
		puts ("You stand freeze before the tree"); sleep(2);
		printf ("0. Open bag\n1. Explore around\n2. climb on the tree\nYou decide to ");
		int option;
		scanf ("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\n", HP); sleep(1);
		if (option==1) {
			puts ("You move around the tree many rounds until you notice something"); sleep(2);
			int temp=rand()%5;
			if (temp==0) {
				puts ("You see a jungle cat"); sleep(2);
				puts ("you want to tame it"); sleep(2);
				puts ("You pat its head"); sleep(2);
				puts ("It doesn't like it and scratchs your face"); sleep(2);
				puts ("-3 HP"); sleep(2); HP-=3; if (HP<=0) {sleep(2); HP=0; break;}
				puts ("It leaves");
			} else if (temp==1) {
				puts ("You see a hole deep down the root of the tree"); sleep(2);
				puts ("You come close to the hole mouth"); sleep(2);
				temp=rand()%2;
				if (temp==0) {
					puts ("A rabbit jumps out"); sleep(2);
					puts ("You chase and kill it"); sleep(2);
					puts ("+1 raw meat"); bag[1][5]++;
				} else {
					puts ("A snake jump out and ready to bite you"); sleep(5);
					printf ("\e[1;1H\e[2J");
					snake (HP);
				}
			} else {
				puts ("You find some edible mushrooms"); sleep(2);
				puts ("Maybe can grill them later"); sleep(2);
				puts ("You put them in your bag"); sleep(2);
				temp=rand()%3+3;
				printf ("+%d mushrooms", temp); bag[1][8]+=temp;
			}
		}
		if (option==2) {
			puts ("You climb up the tree"); sleep(2);
			puts ("So risky"); sleep(2);
			int temp=rand()%5;
			if (temp<2) {
				puts ("You are in half way"); sleep(2);
				puts ("Your foot miss the branch"); sleep(2);
				puts ("You fall"); sleep(2);
				temp=rand()%4+7;
				printf ("-%d HP", temp); HP-=temp; if (HP<=0) {sleep(2); HP=0; break;}
			} else if (temp==2) {
				puts ("You see a hole of fruits in the wway to the top of the tree"); sleep(2);
				puts ("You steal the fruits no matter who they belong to"); sleep(2);
				temp=rand()%2+2;
				printf ("+%d apples\n+1 berry\n", temp); sleep(2); bag[1][0]+=temp; bag[1][1]++;
				puts ("You climb down");
			} else {
				puts ("You reach the top of the tree"); sleep(2);
				puts ("So tired"); sleep(2);
				temp=rand()%5;
				if (temp<3) {
					puts ("You see a nest"); sleep(2);
					puts ("You crawl to it"); sleep(2);
					puts ("There are some eggs inside"); sleep(2);
					puts ("You take the eggs"); sleep(2);
					puts ("So crual"); sleep(2);
					temp=rand()%2+3;
					printf ("+%d eggs\n", temp); sleep(2); bag[1][9]+=temp;
					puts ("You climb down");
				} else {
					puts ("A lot of mushrooms grow up here"); sleep(2);
					puts ("You collect them"); sleep(2);
					temp=rand()%3+5;
					printf ("+%d mushrooms\n", temp); sleep(2); bag[1][8]+=temp;
					puts ("You climb down");
				}
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
