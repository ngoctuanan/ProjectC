#include "game_functions.h"
void waterfall(int &eventcount)
{
	eventcount++;
	while (int keepevent=true) {
		printf ("HP: %d\n", HP); sleep(1);
		puts ("You follow the river flow and see another branch of the river come from a waterfall nearby"); sleep(2);
		puts ("You come toward the waterfall"); sleep(2);
		puts ("There is a way lead to the cave behind the waterfall"); sleep(2);
		printf ("0. Open bag\n1. Go inside the cave\n2. Explore around the waterfall\nYou decide to ");
		int option; scanf("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\n", HP); sleep(1);
		if (option==1) {
			puts ("You head inside the cave"); sleep(2);
			puts ("You take a look"); sleep(2);
			int temp=rand()%10;
			if (temp<2) {
				puts ("Seem mushroom is thriving inside the cave"); sleep(2);
				puts ("You take some mushrooms and put them in your bag"); sleep(2);
				int temp1=rand()%2+3; printf ("+%d mushrooms", temp1); bag[1][8]+=temp1;
			} else {
				puts ("This seems to be a bat cave"); sleep(2);
				int temp1=rand()%10;
				if (temp1<6) {
					puts ("The cave is filled with fruits"); sleep(2);
					puts ("But you don't see any bats"); sleep(2);
					puts ("Maybe they are collecting more fruits outside"); sleep(2);
					puts ("You collect these fruits"); sleep(2);
					int temp2=rand()%2+4; printf ("+%d apples\n", temp2); bag[1][0]+=temp2;
					puts ("+2 berries"); bag[1][1]+=2;
				} else {
					puts ("The bats are hanging to sleep"); sleep(2);
					puts ("You see nothing to take and leave"); sleep(2);
					puts ("You kick a rock accidentally and wake a bat up"); sleep(2);
					puts ("It attacks you"); sleep(5);
					printf ("\e[1;1H\e[2J");
					Bat(HP);
				}
			}
		}
		if (option==2) {
			puts ("You go explore the habitat below the waterfall"); sleep(2);
			int temp1=rand()%20;
			if (temp1<2) {
				puts ("You bend down to check the flow"); sleep(2);
				puts ("Suddenly a bat flys out of the cave"); sleep(2);
				puts ("It sees you and wants to take your bag"); sleep(2);
				puts ("You cant let it have it"); sleep(5);
				printf ("\e[1;1H\e[2J");
				bat(HP);
			} else if (temp1<5) {
				puts ("You keep walking around and a fish falls on your head"); sleep(2);
				puts ("-3 HP"); HP-=3; if (HP<=0) {sleep(2); HP=0; break;} sleep(2);
				int temp2=rand()%10;
				puts ("It must come from the upper waterfall"); sleep(2);
				puts ("You just grab the fish and throw it into your bag anyway"); sleep(2);
				if (temp2<7) {puts ("+1 small fish"); bag[1][2]++;}
					else {puts ("+1 medium fish"); bag[1][3]++;}
			} else if (temp1<9) {
				puts ("Look at the water"); sleep(2);
				puts ("You see a bomb"); sleep(2);
				puts ("Did someone catch fish by exploding?"); sleep(2);
				puts ("You grab the bomb"); sleep(2);
				int temp2=rand()%10;
				if (temp2<4) {puts ("The bomb goes off"); sleep(2); puts ("-18 HP"); HP-=18; if (HP<=0) {sleep(2); HP=0; break;}}
					else {puts ("The bomb may work well"); sleep(2); puts ("You put it in the bag"); sleep(2); puts("+1 bomb"); bag[3][2]++;}
			} else {
				puts ("You see an apple tree and come to examine"); sleep(2);
				puts ("You shake the tree"); sleep(2);
				int temp2=rand()%4;
				if (temp2==0) {puts ("A bee hive falls on your head"); sleep(2); puts ("You get stung"); sleep(2); puts ("-8 HP"); HP-=8; if (HP<=0) {sleep(2); HP=0; break;}}
					else if (temp2==1) {
					puts ("A bat falls off"); sleep(2);
					puts ("It is eatting and you do this to it?"); sleep(2);
					puts ("It turns angry and attacks you"); sleep(5);
					printf ("\e[1;1H\e[2J"); bat(HP);}
					else {puts ("Some apples fall off"); sleep(2); puts ("You take them"); sleep(2); int temp3=rand()%3+2; printf ("+%d apples", temp3); bag[1][0]+=temp3;}
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