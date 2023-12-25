#include "game_functions.h"
void restblurwaterevent (int &eventcount)			//unfinish
{
	eventcount++;
	while (bool keepevent=true) {
		printf ("HP: %d\n", HP); sleep(1);
		puts ("You feel tired and decide to take a rest"); sleep(2);
		puts ("This part of the river has blur water"); sleep(2);
		puts ("You star at the water"); sleep(2);
		printf ("0. Open bag\n1. Jump into the river\n2. Gather some material\nYou decide to ");
		int option; scanf("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\n", HP); sleep(1);
		if (option==1) {
			puts ("You wonder what is under that water"); sleep(2);
			puts ("You jump into the river"); sleep(2);
			int temp=rand()%10;
			if (temp==0) {
				puts ("A big shadow swimming around you"); sleep(2);
				printf ("It disappears"); sleep(1); printf ("."); sleep(1); printf ("."); sleep(1); printf ("."); sleep(2); puts ("");
				puts ("You swim to the land real quick but didn't make it"); sleep(2);
				puts ("That thing bites your leg"); sleep(2);
				int temp1=rand()%6+10;
				printf ("-%d HP\n", temp1); sleep(2); HP-=temp1; if (HP<=0) {sleep(2); HP=0; break;}
				puts ("You try to kick it with the other leg"); sleep(2);
				puts ("It falls off and you make it to the land");
			} else if (temp<3) {
				puts ("You dive down and look for some fishes"); sleep(2);
				puts ("But you don't see see any"); sleep(2);
				puts ("A snake bites you underwater"); sleep(2);
				int temp1=rand()%3+3;
				printf ("-%d HP\n", temp1); sleep(2); HP-=temp1; if (HP<=0) {sleep(2); HP=0; break;}
				puts ("You pull it and throw away"); sleep(2);
				puts ("You swim to the land and it doesn't give up"); sleep(2);
				puts ("The snake follows you"); sleep(5);
				printf ("\e[1;1H\e[2J");
				snake (HP);
			} else {
				puts ("With your special skill"); sleep(2);
				printf ("You catch a ");
				int temp1=rand()%10;
				if (temp1<3) {
					int temp2=rand()%3;
					if (temp2==0) {puts ("smallmouth bass"); sleep(2);}
					if (temp2==1) {puts ("perch"); sleep(2);}
					if (temp2==2) {puts ("bream"); sleep(2);}
					int temp3=rand()%4;
					if (temp3==0) {puts ("But the fish is slippery"); sleep(2); puts ("It jumps off your hands and swims away");}
						else {puts ("+1 small fish"); bag[1][2]++;}
				} else {
					int temp2=rand()%3;
					if (temp2==0) {puts ("rainbow trout"); sleep(2);}
					if (temp2==1) {puts ("walleye"); sleep(2);}
					if (temp2==2) {puts ("pike"); sleep(2);}
					int temp3=rand()%2;
					if (temp3==0) {puts ("But the fish is slippery"); sleep(2); puts ("It jumps off your hands and swims away");}
						else {puts ("+1 medium fish"); bag[1][3]++;}
				}
			}
		}
		if (option==2) {
			puts ("You search for something useful to use"); sleep(2);
			puts ("You push the high grasses aside"); sleep(2);
			int temp=rand()%20;
			if (temp==0) {
				puts ("You see a snake trembling"); sleep(2);
				puts ("It is scared of something but then attack you to defense itself"); sleep(5);
				printf ("\e[1;1H\e[2J");
				snake(HP);
			} else if (temp==1) {
				puts ("You see a tiny rope near damaged stone"); sleep(2);
				puts ("You pull it up"); sleep(2);
				puts ("It is a bomb which you do not know if it still words"); sleep(2);
				puts ("+1 bomb"); sleep(2); bag[3][1]++;
				puts ("You take some stones with you too"); sleep(2);
				int temp1=rand()%2+2;
				printf ("+%d stones", temp1); bag[2][1]+=temp1;
			} else if (temp<19) {
				puts ("You see some mice"); sleep(2);
				puts ("They see you and run away"); sleep(2);
				puts ("But one of them stays and holds your step"); sleep(5);
				printf ("\e[1;1H\e[2J");
				rat(HP);
			} else {
				puts ("Just clays and rocks"); sleep(2);
				puts ("You put them in bag"); sleep(2);
				int temp1=rand()%3+2; printf("+%d clays\n", temp1); sleep(2); bag[2][0]+=temp1;
				int temp2=rand()%3+2; printf("+%d rocks\n", temp2); sleep(2); bag[3][0]+=temp2;
				puts ("After take out clays and rock you see some coins"); sleep(2);
				int temp3=rand()%3+2; printf("+%d coins", temp3); coin+=temp3;
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