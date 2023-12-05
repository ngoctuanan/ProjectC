#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int HP, daycount, coin, bag[4][100]={0};

void equipment ()
{
	while (bool keeppocketopen=true) {
		printf ("HP: %d\t\t\tCoin: %d\n", HP, coin);
		int count=0;
		while (count<1) {
			if (count%5==0) puts("");
			if (bag[0][0]) {printf ("Sword"); count++;}
		}
		printf("\n\n");
		puts ("0. Confirm\n1. Ehh...\nClose pocket? ");
		int option;
		scanf ("%d", &option);
		printf ("\e[1;1H\e[2J");
		if (option==0) break;
	}
}
 
void food ()
{
	bool keeppocketopen=true;
	while (keeppocketopen) {
		printf ("HP: %d\t\t\tCoin: %d\n", HP, coin);
		int count=0, *temp[]={0};
		while (count<6) {
			if (count%5==0) puts("");
			if (bag[1][0]) {printf ("%d. %5s: %d          ", count, "Apple", bag[1][0]); temp[count]=&bag[1][0]; count++;}
			if (bag[1][1]) {printf ("%d. %5s: %d          ", count, "Berry", bag[1][1]); temp[count]=&bag[1][1]; count++;}
			if (bag[1][2]) {printf ("%d. %10s: %d     ", count, "Small fish", bag[1][2]); temp[count]=&bag[1][2]; count++;}
			if (bag[1][3]) {printf ("%d. %11s: %d    ", count, "Medium fish", bag[1][3]); temp[count]=&bag[1][3]; count++;}
			if (bag[1][4]) {printf ("%d. %10s: %d     ", count, "Large fish", bag[1][4]); temp[count]=&bag[1][4]; count++;}
			if (bag[1][5]) {printf ("%d. %8s: %d     ", count, "Raw meat", bag[1][5]); temp[count]=&bag[1][5]; count++;}
			break;
		}
		printf("\n\n");
		printf ("%d. Nothing\nYou want to consume ", count);
		int option;
		scanf ("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tCoin: %d\n", HP, coin); sleep(1);
		if (temp[option]==&bag[1][1]) {
			bag[1][1]--;
			int consume=rand()%10;
			if (consume==0) {puts("The berry was rotten"); sleep(2); puts("-3 HP"); sleep(2); printf ("\e[1;1H\e[2J"); HP-=3; if (HP<0) HP=0;}
			else { consume=rand()%2+2; puts("Fresh berry"); sleep(2); printf("+%d HP", consume); sleep(2); printf ("\e[1;1H\e[2J"); HP+=consume; if (HP>100) HP=100;}
		}
		if (temp[option]==&bag[1][2]) {
			bag[1][2]--;
			int consume=rand()%4;
			if (consume==0) {puts("You get poison from eating raw food"); sleep(2); puts("-7 HP"); sleep(2); printf ("\e[1;1H\e[2J"); HP-=7; if (HP<0) HP=0;}
			else {puts("Small fish does not suply much vitamins"); sleep(2); puts("It is even raw"); sleep(2); puts("+3 HP"); sleep(2); printf ("\e[1;1H\e[2J"); HP+=3; if (HP>100) HP=100;}
		}
		if (temp[option]==&bag[1][3]) {
			bag[1][3]--;
			int consume=rand()%4;
			if (consume==0) {puts("You get poison from eating raw food"); sleep(2); puts("-7 HP"); sleep(2); printf ("\e[1;1H\e[2J"); HP-=7; if (HP<0) HP=0;}
			else {consume=rand()%2+4; puts("Raw medium fish gives fine taste"); sleep(2); printf("+%d HP", consume); sleep(2); printf ("\e[1;1H\e[2J"); HP+=consume; if (HP>100) HP=100;}
		}
		if (temp[option]==&bag[1][4]) {
			bag[1][4]--;
			int consume=rand()%4;
			if (consume==0) {puts("You get poison from eating raw food"); sleep(2); puts("-7 HP"); sleep(2); printf ("\e[1;1H\e[2J"); HP-=7; if (HP<0) HP=0;}
			else {puts("Large fish is delicious"); sleep(2); puts("But is raw"); sleep(2); puts("+6 HP"); sleep(2); printf ("\e[1;1H\e[2J"); HP+=6; if (HP>100) HP=100;}
		}
		if (temp[option]==&bag[1][5]) {
			bag[1][5]--;
			int consume=rand()%4;
			if (consume==0) {puts("You get poison from eating raw food"); sleep(2); puts("-7 HP"); sleep(2); printf ("\e[1;1H\e[2J"); HP-=7; if (HP<0) HP=0;}
			else {puts("Raw meat does not suply much vitamins"); sleep(2); puts("+4 HP"); sleep(2); printf ("\e[1;1H\e[2J"); HP+=4; if (HP>100) HP=100;}
		}
		if (option==count) {
			printf ("0. Confirm\n1. Ehh...\nClose pocket?\n");
			scanf ("%d", &option);
			printf ("\e[1;1H\e[2J");
			if (option==0) break;
		}
	}
}

void material ()
{
	while (bool keeppocketopen=true) {
		printf ("HP: %d\t\t\tCoin: %d\n", HP, coin);
		int count=0;
		while (count<2) {
			if (count%5==0) puts("");
			if (bag[2][0]) {printf ("%4s: %d      ", "Clay", bag[2][0]); count++;}
			if (bag[2][1]) {printf ("%5s: %d     ", "Stone", bag[2][1]); count++;}
			break;
		}
		printf("\n\n");
		puts ("0. Confirm\n1. Ehh...\nClose pocket?\n");
		int option;
		scanf ("%d", &option);
		printf ("\e[1;1H\e[2J");
		if (option==0) break;
	}
}

void goods (int &enemyHP)
{
	bool keeppocketopen=true;
	while (keeppocketopen) {
		printf ("HP: %d\t\t\tCoin: %d\n", HP, coin);
		int count=0, *temp[]={0};
		while (count<2) {
			if (count%5==0) puts("");
			if (bag[3][0]) {printf ("%d. %4s: %d         ", count, "Rock", bag[3][0]); temp[count]=&bag[3][0]; count++;}
			if (bag[3][1]) {printf ("%d. %4s: %d         ", count, "Bomb", bag[3][1]); temp[count]=&bag[3][1]; count++;}
			break;
		}
		printf("\n\n");
		if (enemyHP>0) {
			printf ("%d. Nothing\nYou want to use ", count);
			int option, missrate=rand()%20;
			scanf ("%d", &option);
			printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tCoin: %d\n", HP, coin); sleep(1);
			if (temp[option]==&bag[3][0]) bag[3][0]--;
			if (temp[option]==&bag[3][1]) bag[3][1]--;
			if (option!=count) {
				if (missrate==0) {
					printf ("."); sleep(1); printf ("."); sleep(1); printf ("."); sleep(1); puts("");
					puts("As expected"); sleep(2);
					puts("Due to your bad throwing skill"); sleep(2);
					puts("The thing you threw flys over the enemy and lands on a point far away from the enemy..."); sleep(2);
					puts("welp..."); sleep(2);
					printf ("\e[1;1H\e[2J");
				} else {
					if (temp[option]==&bag[3][0])
						{printf("You throw a rock and it hits enemy's head and does 4 damage"); sleep(3); printf ("\e[1;1H\e[2J"); enemyHP-=4; if (enemyHP<0) enemyHP=0;}
					if (temp[option]==&bag[3][1])
						{puts("You throw a bomb beside the enemy"); sleep(2); puts("It explodes and does 18 damage"); sleep(3); printf ("\e[1;1H\e[2J"); enemyHP-=18; if (enemyHP<0) enemyHP=0;}
					printf ("\e[1;1H\e[2J");
			 	 }
			}
			if (option==count) {
				printf ("0. Confirm\n1. Ehh...\nClose pocket?\n");
				scanf ("%d", &option);
				printf ("\e[1;1H\e[2J");
				if (option==0) break;
			}
		} else {
			puts ("0. Confirm\n1. Ehh...\nClose pocket?\n");
			int option;
			scanf ("%d", &option);
			printf ("\e[1;1H\e[2J");
			if (option==0) break;
		  }
	}
}

void openbag (int &enemyHP)
{
	while (bool keepbagopen=true) {
		printf ("HP: %d\t\t\tCoin: %d\n", HP, coin);
		printf ("0. Nothing\n1. Equipment\n2. Food\n3. Material\n4. Goods\nMaybe open the pocket of ");
		int option;
		scanf ("%d", &option);
		printf ("\e[1;1H\e[2J");
		if (option==1) equipment();
		if (option==2) food();
		if (option==3) material();
		if (option==4) goods(enemyHP);
		if (option==0) {
			printf ("HP: %d\t\t\tCoin: %d\n", HP, coin);
			printf ("0. Confirm\n1. Wait\nClose bag?\n");
			scanf ("%d", &option);
			printf ("\e[1;1H\e[2J");
			if (option==0) break;
		}
	}
	printf ("\e[1;1H\e[2J"); sleep(1);
}

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

void thief (int &HP)
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

void rat (int &HP)			//unfinish
{
	int ratHP=18;
	while (ratHP>0) {
		printf ("HP: %d\t\t\tRat HP: %d\n", HP, ratHP); sleep(1);
		printf ("0. Openbag\n1. Attack\nLet's ");
		int option; scanf ("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tRat HP: %d\n", HP, ratHP); sleep(1);
		if (option==1) {
			int temp=rand()%20;
			if (temp==0) puts ("The rat is small so you can not hit it accurately");
				else {
					temp=rand()%5+8;
					printf ("You land a hit with %d damage on the rat", temp); ratHP-=temp;
					if (ratHP<=0) break;
				}
			sleep(5); printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tRat HP: %d\n", HP, ratHP); sleep(1);
			temp=rand()%50;
			if (temp==0) puts ("The rat jump to bite you but you block it");
				else {
					temp=rand()%2+1;
					puts ("The rat bites you"); sleep(2);
					printf ("-%d HP\n", temp); HP-=temp; if (HP<=0) {sleep(2); HP=0; break;}
					temp=rand()%2;
					if (temp==0) {
						sleep(2);
						puts("It quickly bite you again"); sleep(2);
						temp=rand()%2+1;
						printf ("-%d HP\n", temp); HP-=temp; if (HP<=0) {sleep(2); HP=0; break;}
					}
				}
			sleep(5); printf ("\e[1;1H\e[2J");
		}
		if (option==0) {printf ("\e[1;1H\e[2J"); openbag(ratHP);}
	}
	if (ratHP<=0) {
		printf ("HP: %d\n", HP); sleep(1);
		puts ("You kill the rat"); sleep(2);
		int temp=rand()%2+2;
		puts ("You got"); sleep(2); printf ("+%d coins\n", temp); coin+=temp;
		temp=rand()%2;
		if (temp==0) {sleep(2); puts("This rat was big enough for you to take its meat"); sleep(2); puts("+1 raw meat"); bag[1][5]++;}
	}
}

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
			} else if (temp<7) {
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

void berrybushevent (int &eventcount)
{
	eventcount++;
	while (bool keepevent=true) {
	printf ("HP: %d\n", HP); sleep(1);
	printf ("You are walking and berry bushes along the river catch your sight\n"); sleep(1);
	printf ("0. Open bag\n1. Harvest some berries\n2. Ignore it\n3. Star at the bushes\nYou decide to ");
	int option; scanf("%d", &option);
	printf ("\e[1;1H\e[2J"); printf ("HP: %d\n", HP); sleep(1);
	if (option==1) {
		int temp=rand()%5+3;
		puts ("You walk toward and pick some berries"); sleep(2);
		printf ("+%d berries\n", temp); bag[1][1]+=temp;
		temp=rand()%10;
		if (temp<3) {
			sleep(1);
			printf ("Wait"); sleep(1); printf ("."); sleep(1); printf ("."); sleep(1); printf ("."); sleep(1); puts("");
			puts ("You step on ants hill when you are about to leave"); sleep(2);
			puts ("It is your fault for being clumsy"); sleep(2);
			puts ("Now they climb up and bite you"); sleep(2);
			temp=rand()%3+1;
			printf ("-%d HP", temp); HP-=temp; if (HP<0) HP=0;
		}
	}
	if (option==2) {
		int temp=rand()%10;
		if (temp>2) puts ("Although how delicious these berries look like, you walk away...");
		else {
			puts ("You turn your head away and suddenly a snake jumps out from the bushes and attacks you");
			sleep(5);
			printf ("\e[1;1H\e[2J");
			snake (HP);
		}
	}
	if (option==3) {
		int temp=rand()%10;
		if (temp<7) {puts ("You just pick a berry and leave"); sleep(2); puts ("+1 berry"); bag[1][1]++;}
		else {
			temp=rand()%3+1;
			if (temp==1) {puts ("You notice something shiny thought the bushes"); sleep(2); puts ("It is a coin"); sleep(2); puts ("+1 coin"); coin++;}
			else {puts ("You notice something shiny thought the bushes"); sleep(2); puts ("they are coins"); sleep(2); printf("+%d coin", temp); coin+=temp;}
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

void fishermanevent (int &eventcount)
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

void river (int &eventcount)
{
	int blockrepeat[3]={0}, locate=0;
	while (eventcount<3) {
		int temp=rand()%3+1;
		if (blockrepeat[0]==temp||blockrepeat[1]==temp||blockrepeat[2]==temp) continue;
		blockrepeat[locate]=temp; locate++;
		if (temp==1) berrybushevent (eventcount);
		if (temp==2) fishermanevent (eventcount);
		if (temp==3) restblurwaterevent (eventcount);
		if (HP==0) break;
	}
}

void startday (int &eventcount)
{
	while (bool keepday=true){
	printf ("HP: %d\n", HP); sleep(1);
	printf ("Day %d\n", daycount); sleep(1);
	printf ("Where do you want to go?\n0. Open bag\n1. Go to the river bank\nLet's ");
	int option;
	scanf ("%d", &option);
	printf ("\e[1;1H\e[2J");
	if (option==1) river(eventcount);
	if (option==0) {int blockusegoods=0; openbag(blockusegoods);}
		else break;
	}
}

void dayloop (int &daycount)
{
	daycount++;
	int eventcount=0;
	startday (eventcount);
}

void process (int &HP)
{
	while (HP>0) {
		dayloop (daycount);
 	}
	if (HP==0) {
		sleep(3);
		printf ("\e[1;1H\e[2J");
		printf ("Game over\nYou survived %d days\n\t1. Start a new life\n\t2. Exit\nYou want to ", daycount);
		int option;
		scanf ("%d", &option);
		printf ("\e[1;1H\e[2J");
		if (option==1) {
			HP=100; daycount=0; coin=0; bag[0][0]=1;
			process (HP);
		}
		if (option==2) printf ("Thanks for playing");
	}
}

int main (void)
{
	HP=100; daycount=0; coin=0; bag[0][0]=1;
	srand(time(NULL));
	process (HP);
}

