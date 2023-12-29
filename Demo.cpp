#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>	
int HP, daycount, coin, bag[4][100]={0}, dame ;
void BuyWeapon() {
    int choice;

    do {
        puts("You have chosen to buy a weapon.\n");
        printf("Your coin: %d\n", coin);
        puts("1. LongSword: (15 coins to purchase, and it deals 5 damage.) \n");
        puts("2. Bow: (10 coins to purchase, and it grants 4 damage.)\n");
        puts("3. The dagger (20 coins to buy, deals 7 damage, and has an additional attack effect with a 15% chance.)\n");
        puts("0. Nothing");

        sleep(2);
        scanf("%d", &choice);
        printf("\e[1;1H\e[2J");

        switch (choice) {
            case 1:
                if (coin >= 15) {
                    dame += 5;
                    coin -= 15;
                    sleep(2);
                    printf("You have purchased a longsword, and it deals 5 damage. Your total damage is now: %d \n", dame);
                } else {
                    sleep(2);
                    puts("I'm sorry, but you don't have enough money to complete the transaction.");
                }
                break;
            case 2:
                if (coin >= 10) {
                    dame += 4;
                    coin -= 10;
                    sleep(2);
                    printf("You choose to buy a wooden bow. It deals 4 damage, and your current total damage is  %d\n", dame);
                } else {
                    sleep(2);
                    puts("I'm sorry, but you don't have enough money to complete the transaction.\n");
                }
                break;
            case 3:
                if (coin >= 20) {
                    dame += 7;
                    coin -= 20;
                    sleep(2);
                    printf("You choose to buy the dagger. It deals 7 damage, and your current total damage is %d\n", dame);
                } else {
                    sleep(2);
                    puts("I'm sorry, but you don't have enough money to complete the transaction.\n");
                }
                break;
            case 0:
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 0);
}
void buyequiment(){
	int choice;
	do {
        printf("Your coin: %d\n", coin);
        puts("1. Health Potion: (Cost: 5 coins, Restores 15 HP.) \n");
        puts("2. Lucky Dice: (Cost: 5 coins, 5% chance to receive 10 coins.)\n");
        puts("3. Large Healing Potion: (Cost: 50 coins, 3% chance to add 100 HP.)\n");
        puts("0. Nothing");

        scanf("%d", &choice);
        printf("\e[1;1H\e[2J");

        switch (choice) {
            case 1:
                if (coin >= 5) {
                    if (HP < 100) {
                        HP += 15;
                        coin -= 5;
                        printf("You bought a Health Potion. It restores 15 HP. Your current HP is now: %d\n", HP);
                    } else {
                        puts("Your HP is already full. No need to purchase a Health Potion.");
                    }
                } else {
                    puts("Sorry, you don't have enough coins to complete the transaction.");
                }
                break;
            case 2:
                if (coin >= 5) {
                    coin -= 5;
                    if (rand() % 100 < 5) {
                        coin += 10;
                        printf("You bought a Lucky Dice. You received 10 coins. Your current coins are now: %d\n", coin);
                    } else {
                        puts("You bought a Lucky Dice. Unfortunately, you didn't win any coins.");
                    }
                } else {
                    puts("Sorry, you don't have enough coins to complete the transaction.");
                }
                break;
            case 3:
                if (coin >= 50) {
                    if (HP < 100) {
                        coin -= 50;
                        if (rand() % 100 < 3) {
                            HP += 100;
                            if (HP > 100) {
                                HP = 100;
                            }
                            printf("You bought a Large Healing Potion. It added 100 HP. Your current HP is now: %d\n", HP);
                        } else {
                            puts("You bought a Large Healing Potion. Unfortunately, it didn't have the extra healing effect.");
                        }
                    } else {
                        puts("Your HP is already full. No need to purchase a Large Healing Potion.");
                    }
                } else {
                    puts("Sorry, you don't have enough coins to complete the transaction.");
                }
                break;
            case 0:
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 0);
}
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
		if (HP==0) break;
	}
	printf ("\e[1;1H\e[2J"); sleep(1);
}

void snake(int &HP) {
    int snakeHP = 30;

    while (snakeHP > 0 && HP > 0) {
        printf("HP: %d\t\t\tSnake HP: %d\n", HP, snakeHP);
        sleep(1);
        printf("0. Open bag\n1. Attack\nLet's ");
        int option;
        scanf("%d", &option);
        printf("\e[1;1H\e[2J");
        printf("HP: %d\t\t\tSnake HP: %d\n", HP, snakeHP);
        sleep(1);

        if (option == 1) {
            int temp = rand() % 20;
            if (temp == 0) {
                puts("The snake dodged and you hit the ground");
            } else {
                temp = rand() % 5 + 8 + dame;  
                printf("You land a hit with %d damage on the snake", temp);
                snakeHP -= temp;
                if (snakeHP <= 0) break;
            }
            sleep(5);
            printf("\e[1;1H\e[2J");
            printf("HP: %d\t\t\tSnake HP: %d\n", HP, snakeHP);
            temp = rand() % 100;
            if (temp < 7) {
                puts("The snake attacks with poisonous ball but you dodge");
            } else {
                temp = rand() % 3 + 3;
                puts("The snake throws up poisonous ball on you");
                sleep(2);
                printf("-%d HP\n", temp);
                HP -= temp;
                if (HP <= 0) {
                    sleep(2);
                    HP = 0;
                    break;
                }
                temp = rand() % 10;
                if (temp < 3) {
                    sleep(1);
                    printf("Wait");
                    sleep(1);
                    printf(".");
                    sleep(1);
                    printf(".");
                    sleep(1);
                    printf(".");
                    sleep(1);
                    puts("");
                    puts("You get affected by poison");
                    sleep(2);
                    printf("-7 HP");
                    HP -= 7;
                    if (HP <= 0) {
                        sleep(2);
                        HP = 0;
                        break;
                    }
                }
            }
            sleep(5);
            printf("\e[1;1H\e[2J");
        }

        if (option == 0) {
            printf("\e[1;1H\e[2J");
            openbag(snakeHP);
        }
    }

    if (snakeHP <= 0 && HP > 0) {
        sleep(5);
        printf("\e[1;1H\e[2J");
        printf("HP: %d\n", HP);
        sleep(1);
        puts("The snake dies and you get");
        int temp = rand() % 4 + 3;
        printf("+%d coins\n", temp);
        coin += temp;
        temp = rand() % 10;
        if (temp != 0) {
            printf("+1 raw meat");
            bag[1][5]++;
        }
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
					temp=rand()%5+8 + dame;
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

void rat (int &HP)			
{
	int ratHP=18;
	while (ratHP>0) {
		printf ("HP: %d\t\t\tRat HP: %d\n", HP, ratHP); sleep(1);
		printf ("0. Open bag\n1. Attack\nLet's ");
		int option; scanf ("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tRat HP: %d\n", HP, ratHP); sleep(1);
		if (option==1) {
			int temp=rand()%20;
			if (temp==0) puts ("The rat is small so you can not hit it accurately");
				else {
					temp=rand()%5+8 + dame;
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
		sleep(5); printf ("\e[1;1H\e[2J");
		printf ("HP: %d\n", HP); sleep(1);
		puts ("You kill the rat"); sleep(2);
		int temp=rand()%2+2;
		puts ("You got"); sleep(2); printf ("+%d coins\n", temp); coin+=temp;
		temp=rand()%2;
		if (temp==0) {sleep(2); puts("This rat was big enough for you to take its meat"); sleep(2); puts("+1 raw meat"); bag[1][5]++;}
	}
}

void bat (int &HP)			
{
	int batHP=23;
	while (batHP>0) {
		printf ("HP: %d\t\t\tBat HP: %d\n", HP, batHP); sleep(1);
		printf ("0. Open bag\n1. Attack\nLet's ");
		int option; scanf ("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tBat HP: %d\n", HP, batHP); sleep(1);
		if (option==1) {
			int temp=rand()%20;
			if (temp==0) puts ("You slash the bat but it flys up");
				else {
					temp=rand()%5+8 + dame;
					printf ("You stab the bat with %d damage", temp); batHP-=temp;
					if (batHP<=0) break;
				}
			sleep(5); printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tBat HP: %d\n", HP, batHP); sleep(1);
			temp=rand()%20;
			if (temp==0) puts ("The bat flys downward to you and open its mouth to bite but you block its mouth with your sword");
				else {
					temp=rand()%2+2;
					puts ("The bat bites you"); sleep(2);
					printf ("-%d HP\n", temp); HP-=temp; if (HP<=0) {sleep(2); HP=0; break;}
				}
			sleep(5); printf ("\e[1;1H\e[2J");
		}
		if (option==0) {printf ("\e[1;1H\e[2J"); openbag(batHP);}
	}
	if (batHP<=0) {
		sleep(5); printf ("\e[1;1H\e[2J");
		printf ("HP: %d\n", HP); sleep(1);
		puts ("You kill the bat"); sleep(2);
		int temp=rand()%2+2;
		puts ("You got"); sleep(2); printf ("+%d coins\n", temp); sleep(2); coin+=temp;
		puts ("An apple and a berry fall off the bat body"); sleep(2);
		puts ("+1 apple"); bag[1][0]++;
		puts ("+1 berry"); bag[1][1]++;
		temp=rand()%10;
		if (temp<4) {sleep(2); puts ("A bat hears its friend scream"); sleep(2); puts ("it comes to revenge"); sleep(5); printf ("\e[1;1H\e[2J"); bat(HP);}
	}
}

void bear (int &HP)
{
	int bearHP=75;
	while (bearHP>0) {
		printf ("HP: %d\t\t\tBear HP: %d\n", HP, bearHP); sleep(1);
		printf ("0. Open bag\n1. Attack\nLet's ");
		int option; scanf ("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tBear HP: %d\n", HP, bearHP); sleep(1);
		if (option==1) {
			int temp=rand()%20;
			if (temp==0) puts ("You stab the bear but it blocks your sword");
				else {
					temp=rand()%5+8 + dame;
					printf ("You slash the bear with %d damage", temp); bearHP-=temp;
					if (bearHP<=0) break;
				}
			sleep(5); printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tBear HP: %d\n", HP, bearHP); sleep(1);
			temp=rand()%50;
			if (temp<9) puts ("You dodge when the bear run toward you");
				else {
					temp=rand()%3+10;
					puts ("The bear jumps up and lands behind you to bite"); sleep(2);
					printf ("-%d HP\n", temp); HP-=temp; if (HP<=0) {sleep(2); HP=0; break;}
					temp=rand()%5;
					if (temp<2) {
						sleep(2);
						puts ("That was a deep bite"); sleep(2);
						puts ("The wound starts bleeding"); sleep(2);
						puts ("-5 HP"); HP-=5; if (HP<=0) {sleep(2); HP=0; break;}
						temp=rand()%4;
						if (temp<3) {sleep(2); puts ("It keeps bleeding"); sleep(2); puts ("-5 HP"); HP-=5; if (HP<=0) {sleep(2); HP=0; break;}}
					}
				}
			sleep(5); printf ("\e[1;1H\e[2J");
		}
		if (option==0) {printf ("\e[1;1H\e[2J"); openbag(bearHP);}
	}
	if (bearHP<=0) {
		sleep(5); printf ("\e[1;1H\e[2J");
		printf ("HP: %d\n", HP); sleep(1);
		puts ("You finally defeat that bear"); sleep(2);
		int temp=rand()%3+13;
		puts ("You got"); sleep(2); printf ("+%d coins\n", temp); sleep(2); coin+=temp;
		temp=rand()%2+3;
		puts ("You stab the bear dead body for its meat");
		printf ("+%d raw meat", temp); bag[1][5]+=temp;
	}
}

void wolf (int &HP)
{
	int wolfHP=55;
	while (wolfHP>0) {
		printf ("HP: %d\t\t\tWolf HP: %d\n", HP, wolfHP); sleep(1);
		printf ("0. Open bag\n1. Attack\nLet's ");
		int option; scanf ("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tWolf HP: %d\n", HP, wolfHP); sleep(1);
		if (option==1) {
			int temp=rand()%20;
			if (temp==0) puts ("You stab the wolf but it jumps back");
				else {
					temp=rand()%5+8 + dame;
					printf ("You kick the sword hilt and it stabs the wolf with %d damage\n", temp); wolfHP-=temp; sleep(2);
					puts ("You avoid the wolf and take the sword back");
					if (wolfHP<=0) break;
				}
			sleep(5); printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tWolf HP: %d\n", HP, wolfHP); sleep(1);
			temp=rand()%25;
			if (temp<2) puts ("The wolf bite you but you dodge and it bites the air surrounding you instead");
				else {
					temp=rand()%2+9;
					puts ("The wolf damages you with its claws"); sleep(2);
					printf ("-%d HP\n", temp); HP-=temp; if (HP<=0) {sleep(2); HP=0; break;}
					temp=rand()%10;
					if (temp==0) {
						sleep(2);
						puts ("That was a deep bite"); sleep(2);
						puts ("The wound starts bleeding"); sleep(2);
						puts ("-5 HP"); HP-=5; if (HP<=0) {sleep(2); HP=0; break;}
						temp=rand()%4;
						if (temp<3) {sleep(2); puts ("It keeps bleeding"); sleep(2); puts ("-5 HP"); HP-=5; if (HP<=0) {sleep(2); HP=0; break;}}
					}
				}
			sleep(5); printf ("\e[1;1H\e[2J");
		}
		if (option==0) {printf ("\e[1;1H\e[2J"); openbag(wolfHP);}
	}
	if (wolfHP<=0) {
		sleep(5); printf ("\e[1;1H\e[2J");
		printf ("HP: %d\n", HP); sleep(1);
		puts ("You defeat the wolf"); sleep(2);
		puts ("That was..."); sleep(2);
		int temp=rand()%2+9;
		puts ("You got"); sleep(2); printf ("+%d coins\n", temp); sleep(2); coin+=temp;
		puts ("You slash some meat from the wolf dead body"); sleep(2);
		printf ("+2 raw meat", temp); bag[1][5]+=2;
	}
}

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
					temp=rand()%5+8 + dame;
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

void waterfall (int &eventcount)
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
					bat(HP);
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

void fruitbasket (int &eventcount)
{
	eventcount++;
	while (bool keepevent=true) {
		printf ("HP: %d\n", HP); sleep(1);
		puts ("You see a basket left beside the river"); sleep(2);
		puts ("You come close and see that is the basket of fruits"); sleep(2);
		printf ("0. Open bag\n1. Take all fruit\n2. Just take an apple\nYou decide to ");
		int option; scanf("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\n", HP); sleep(1);
		if (option==1) {
			puts ("You pick up the basket"); sleep(2);
			int temp=rand()%10;
			if (temp<3) {
				puts ("A monkey appears and steal the basket from you"); sleep(2);
				puts ("You cant let it have the basket"); sleep(5);
				printf ("\e[1;1H\e[2J");
				monkey (HP);
				if (HP==0) break; else {
					sleep(5); printf ("\e[1;1H\e[2J");
					printf ("HP: %d\n", HP); sleep(1);
					puts ("You take the basket back from the monkey"); sleep(2);
				}
			}
			puts ("From the basket you get"); sleep(2);
			temp=rand()%2+2;
			printf ("+%d apples\n", temp); bag[1][0]+=temp;
			puts ("+1 banana"); bag[1][6]++;
			temp=rand()%3+2;
			printf ("+%d berries", temp); bag[1][1]+=temp;
		}
		if (option==2) {
			puts ("You take a look"); sleep(2);
			puts ("You choose the best apple and take a bite"); sleep(2);
			int temp=rand()%4+7;
			printf ("+%d HP", temp); HP+=temp; if (HP>100) HP=100;
			temp=rand()%5;
			if (temp==0) {
				sleep(2);
				puts ("\nThe owner of the basket comes back right the time to see you bite their fruit"); sleep(2);
				puts ("She wants you to pay for that apple"); sleep(2);
				if (coin>=5) {puts ("-5 coins"); coin-=5; sleep(2); puts("The woman takes the basket and leaves");}
					else if (coin==0) {puts ("You do not have any coin"); sleep(2); puts ("The woman is angry"); sleep(2); puts("she takes the basket and leaves");}
						else {printf ("-%d coin"); if (coin!=1) printf("s"); coin=0; sleep(2); puts (""); puts("The woman takes the basket and leaves");}
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

void gianttree (int &eventcount)
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
void cook ()
{
	while (bool cooking=true) {
		int count=0;
		char temp[100][30];
		printf ("HP: %d\n", HP); sleep(1);
		if (bag[1][5]&&bag[1][9]) {printf ("%d. Bacon and egg\t", count); strcpy(temp[count], "Bacon and egg"); count++;}
		if (bag[1][5]) {printf ("%d. Cooked meat\t", count); strcpy(temp[count], "Cooked meat"); count++;}
		if (bag[1][2]) {printf ("%d. Cooked small fish\t", count); strcpy(temp[count], "Cooked small fish"); count++;}
		if (bag[1][3]) {printf ("%d. Cooked medium fish\t", count); strcpy(temp[count], "Cooked medium fish"); count++;}
		if (bag[1][4]) {printf ("%d. Cooked large fish\t", count); strcpy(temp[count], "Cooked large fish"); count++;}
		if (bag[1][9]>=2) {printf ("%d. Fried egg\t", count); strcpy(temp[count], "Fried egg"); count++;} puts ("");
		puts ("");
		printf ("%d. Nothing", count);
		int option;
		printf ("You want to cook ");
		scanf ("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\n", HP); sleep(1);
		if (strcmp(temp[option], "Bacon and egg")==0) {
			puts ("-1 raw meat\n-1 egg\n\n+1 Bacon and egg"); sleep(2);
			bag[1][5]--; bag[1][9]--; bag[1][14]++;  printf ("\e[1;1H\e[2J");
		}
		if (strcmp(temp[option], "Cooked meat")==0) {
			puts ("-1 raw meat\n\n+1 cooked meat"); sleep(2);
			bag[1][5]--; bag[1][13]++;  printf ("\e[1;1H\e[2J");
		}
		if (strcmp(temp[option], "Cooked small fish")==0) {
			puts ("-1 small fish\n\n+1 cooked small fish"); sleep(2);
			bag[1][2]--; bag[1][10]++;  printf ("\e[1;1H\e[2J");
		}
		if (strcmp(temp[option], "Cooked medium fish")==0) {
			puts ("-1 medium fish\n\n+1 cooked medium fish"); sleep(2);
			bag[1][3]--; bag[1][11]++;  printf ("\e[1;1H\e[2J");
		}
		if (strcmp(temp[option], "Cooked large fish")==0) {
			puts ("-1 large fish\n\n+1 cooked large fish"); sleep(2);
			bag[1][4]--; bag[1][12]++;  printf ("\e[1;1H\e[2J");
		}
		if (strcmp(temp[option], "Fried egg")==0) {
			puts ("-2 egg\n\n+1 fried egg"); sleep(2);
			bag[1][9]-=2; bag[1][15]++;  printf ("\e[1;1H\e[2J");
		}
		if (option==count) {
			printf ("0. Confirm\n1. No\nEnd cooking?\n");
			scanf ("%d", &option);
			printf ("\e[1;1H\e[2J");
			if (option==0) break;
		}
	}
}

void giantfish (int &HP)
{
	int gfHP=60, temp;
	bool stun=false;
	while (gfHP>0) {
		printf ("HP: %d\t\t\tGiant fish HP: %d\n", HP, gfHP); sleep(1);
		if (stun==true) {
			temp=rand()%5;
			if (temp<3) {
				stun=false;
				printf ("You finally escape from the weed");
			} else printf ("You struggle to get out of the weed but unsuccessful");
			sleep (3);
		}
		while (stun==false) {
			printf ("\e[1;1H\e[2J");
			printf ("HP: %d\t\t\tGiant fish HP: %d\n", HP, gfHP); sleep(1);
			printf ("0. Open bag\n1. Attack\nLet's ");
			int option; scanf ("%d", &option);
			printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tGiant fish HP: %d\n", HP, gfHP); sleep(1);
			if (option==1) {
				temp=rand()%5;
				if (temp==0) printf ("The fish swims so fast you cant event hit it accurately");
				else {
					temp=rand()%5+8;
					puts ("The fish swims near you"); sleep(2);
					printf ("You take the chance and stab the fish with %d damage", temp); gfHP-=temp;
					if (gfHP<=0) break;
				}
				break;
			}
			if (option==0) {printf ("\e[1;1H\e[2J"); openbag(gfHP);}
		}
		if (gfHP>0) {
		sleep (5); printf ("\e[1;1H\e[2J"); printf ("HP: %d\t\t\tGiant fish HP: %d\n", HP, gfHP); sleep(1);
		temp=rand()%50;
		if (temp==0) {
			puts ("The fish uses its tail to land on you but you swim out of that area"); sleep(2);
			puts ("It smashs the water surface instead");
		} else {
			temp=rand()%4+7;
			puts ("The uses its tail and smashes your body"); sleep(2);
			printf ("-%d HP\n", temp); HP-=temp;
			if (HP<=0) { sleep(2); HP=0; break;}
			if (stun==false) {
				temp=rand()%10;
				if (temp<3) {
					stun=true;
					sleep(2);
					puts ("Suddenly you feel something touches your leg"); sleep(2);
					puts ("The weeds?"); sleep(2);
					puts ("Then it ties your leg"); sleep(2);
					puts ("It climbs up your body");
				}
			}
		}
		sleep (5); printf ("\e[1;1H\e[2J");
		}
	}
	if (gfHP<=0) {
		sleep(5); printf ("\e[1;1H\e[2J");
		printf ("HP: %d\n", HP); sleep(1);
		puts ("You defeat the fish"); sleep(2);
		puts ("Welp"); sleep(2);
		puts ("Here is what you get"); sleep(2);
		temp=rand()%6+10;
		printf ("+%d coins\n", temp); coin+=temp;
		temp=rand()%2+2;
		printf ("+%d large fishes\n", temp); bag[1][4]+=temp;
		temp=rand()%2+3;
		printf ("+%d small fishes", temp); bag[1][3]+=temp;
	}
}

void unexpectedflood (int &eventcount)
{
	eventcount++;
	while (bool keepevent=true) {
		printf ("HP: %d\n", HP); sleep(1);
		puts ("You are walking along the river and suddenly feel the earthquake"); sleep(2);
		puts ("It stops"); sleep(2);
		puts ("The level of water is rising"); sleep(2);
		puts ("The flood is flowing to you"); sleep(2);
		puts ("Run"); sleep(2);
		puts ("You get swept by the flood"); sleep(2);
		printf ("0. Open bag\n1. Swim downstream\n2. Swim against the flood current\n3. Try getting to any highland\nYou decide to ");
		int option; scanf("%d", &option);
		printf ("\e[1;1H\e[2J"); printf ("HP: %d\n", HP); sleep(1);
		if (option==1) {
			puts ("You swim together with the flow of the flood"); sleep(2);
			int temp=rand()%10;
			if (temp<3) {
				puts ("A bomb flows to you while swimming"); sleep(2);
				puts ("Does this count as luck?"); sleep(2);
				puts ("+1 bomb"); bag[3][1]++;
			} else if (temp<7) {
				puts ("A snake swims toward you in order to cling to you"); sleep(5);
				printf ("\e[1;1H\e[2J"); snake (HP);
			} else {
				puts ("A big shadow swims following you"); sleep(2);
				puts ("It jumps into the sky"); sleep(2);
				puts ("Such a big fish"); sleep(2);
				puts ("And its want to eat you"); sleep(5);
				printf ("\e[1;1H\e[2J"); giantfish (HP);
				if (HP=0) break;
			}
		}
		if (option==2) {
			puts ("You swim against the flood"); sleep(2);
			puts ("You want to try to stand still in the water"); sleep(2);
			int temp=rand()%20;
			if (temp<5) {
				puts ("A log flows to you and hits you while you don't notice"); sleep(2);
				temp=rand()%4+8;
				printf ("-%d HP", temp); HP-=temp;
				if (HP<=0) {sleep (2); HP=0; break;}
			} else if (temp<11) {
				puts ("A school of fish swims across you"); sleep(2);
				puts ("They scratch you"); sleep(2);
				temp=rand()%3+3;
				printf ("-%d HP\n", temp); sleep(2); HP-=temp;
				if (HP<=0) {sleep (2); HP=0; break;}
				puts ("You catch some fishes by the chance");
				puts ("+1 large fish"); bag[1][4]++;
				puts ("+2 medium fishes"); bag[1][3]+=2;
				puts ("Some small fishes also stuck in your bag");
				temp=rand()%2+3;
				printf ("+%d small fishes", temp); bag[1][2]+=temp;
			} else {
				puts ("A big shadow swims toward you"); sleep(2);
				puts ("It jumps into the sky"); sleep(2);
				puts ("Such a big fish"); sleep(2);
				puts ("And its want to eat you"); sleep(5);
				printf ("\e[1;1H\e[2J"); giantfish (HP);
				if (HP=0) break;
			}
		}
		if (option==3) {
			puts ("You observe and found a high land that water lever can't reach"); sleep(2);
			int temp=rand()%10;
			if (temp<7) {
				puts ("You see a shadow underwater coming from that direction"); sleep(2);
				puts ("It disappears"); sleep(2);
				puts ("Your leg is bitten from something"); sleep(2);
				puts ("dang it"); sleep(2);
				temp=rand()%4+7;
				printf ("-%d HP\n", temp); sleep(2); HP-=temp;
				if (HP<=0) {sleep (2); HP=0; break;}
				puts ("You manage to get risk of it"); sleep(2);
				temp=rand()%2;
				if (temp==0) {
					puts ("You swim too slow and got bitten again"); sleep(2);
					temp=rand()%4+7;
					printf ("-%d HP\n", temp); sleep(2); HP-=temp;
					if (HP<=0) {sleep (2); HP=0; break;}
					puts ("You manage to get risk of it again"); sleep(2);
					temp=rand()%2;
						if (temp==0) {
						puts ("You swim not fast and got bitten third time"); sleep(2);
						temp=rand()%4+7;
						printf ("-%d HP\n", temp); sleep(2); HP-=temp;
						if (HP<=0) {sleep (2); HP=0; break;}
						puts ("You manage to get risk of it"); sleep(2);
					}
				}
				puts ("You reach high corncave down land");
			} else {
				puts ("With all attemps you reach the land"); sleep(2);
				puts ("You are taking break and see a man is also coming here"); sleep(2);
				puts ("You help him to climb up"); sleep(2);
				puts ("He walks around and gathers some branches to start a fire"); sleep(2);
				puts ("You take the chance to cook something"); sleep(2);
				printf ("\e[1;1H\e[2J");
				cook ();
			}
		}
		if (option==0) {printf ("\e[1;1H\e[2J"); int blockusegoods=0; openbag(blockusegoods);}
		else {
			sleep(5);
			printf ("\e[1;1H\e[2J");
			printf ("HP: %d\n", HP); sleep(1);
			puts ("The water is slowly lowing"); sleep(2);
			puts ("Everything is peaceful now"); sleep(2);
			sleep(3); printf ("\e[1;1H\e[2J");
			break;
		}
	}
}
void Merchant(int &eventcount){
	 eventcount++;
     int choice;
     while (true){
	 printf ("HP: %d\n", HP); sleep(1);	
	 puts("You see an old man standing under a tree");sleep(2);
	 puts("You step forward and he calls out to you");sleep(2);
	 puts("The old man is a merchant and he invites you to buy his goods");sleep(2);
	 printf ("\e[1;1H\e[2J");	
	 do{
	 printf("Welcome to Merchain's shop!\n");sleep(1);
	 puts("0. Open bag\n");sleep(1);
	 puts("1. Buy Weapon\n");sleep(1);
	 puts("2. Buy Equiment\n");sleep(1);
	 puts("3. Exit\n");sleep(2);
	 puts("Now! tell me your option boy");
	 scanf("%d", &choice);
	 printf ("\e[1;1H\e[2J");
	 int demo;
	 switch (choice)
	 {
	 case 0:
	     puts("Let's go your bag\n");
		 demo = 1;
		 openbag(demo);
		 break;	
	 case 1: 
	     BuyWeapon();
		 break;
	 case 2:
	     puts("You have chosen to buy an item.\n");
		 buyequiment();
		 break;
	 case 3:
	     puts("Thank you for visiting shop!\n");
		 printf ("\e[1;1H\e[2J");
		 return;	 
	 default:
		 puts("Invalid option. Please choose again.\n");
	 }
	 printf ("\e[1;1H\e[2J");
	 }
	 while (choice != 3);
    }
}

void river (int &eventcount)
{
	int blockrepeat[5]={0}, locate=0;
	while (eventcount<6) {
		int temp=rand()%7;
		if (blockrepeat[0]==temp||blockrepeat[1]==temp||blockrepeat[2]==temp||blockrepeat[3]==temp) continue;
		blockrepeat[locate]=temp; locate++;
		if (temp==1) berrybushevent (eventcount);
		if (temp==2) fishermanevent (eventcount);
		if (temp==3) restblurwaterevent (eventcount);
		if (temp==4) waterfall (eventcount);
		if (temp==5) fruitbasket (eventcount);
		if (temp==6) Merchant(eventcount);
		if (HP==0) break;
	}
}
void forest (int &eventcount)
{
	int blockrepeat[4]={0}, locate=0;
	while (eventcount<5) {
		int temp=rand()%5+1;
		if (blockrepeat[0]==temp||blockrepeat[1]==temp) continue;
		blockrepeat[locate]=temp; locate++;
		if (temp==1) gianttree (eventcount);
		if (temp==2) dangerforest (eventcount);
		if (temp==3) unexpectedflood(eventcount);
		if (temp==4) Merchant(eventcount);
		if (HP==0) break;
	}
}

void startday (int &eventcount)
{
	while (bool keepday=true){
	printf ("HP: %d\n", HP); sleep(1);
	printf ("Day %d\n", daycount); sleep(1);
	printf ("Where do you want to go?\n0. Open bag\n1. Go to the river bank\n2. Go explore the forest\nLet's ");
	int option;
	scanf ("%d", &option);
	printf ("\e[1;1H\e[2J");
	if (option==1) river(eventcount);
	if (option==2) forest(eventcount);
	if (option==0) {int blockusegoods=0; openbag(blockusegoods);}
		else break;
	}
}

void oop (int &daycount)
{
	daycount++;
	int eventcount=0;
	startday (eventcount);
}

void process(int &HP) {
    while (HP > 0) {
        oop(daycount);
    }
    // Game Over Condition:	
    if (HP == 0) {sleep(3);
        printf("\e[1;1H\e[2J");
        printf("Game over\nYou survived %d days\n\t1. Start a new life\n\t2. Exit\nYou want to ", daycount);
        // User Choice:
        int option;
        scanf("%d", &option);
        printf("\e[1;1H\e[2J");

        // Restart Option:
        if (option == 1) {
            HP = 100;
            daycount = 0;
            coin = 0;

        // Reset Bag Inventory:
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 10; j++)
                    bag[i][j] = 0;

            bag[0][0] = 1;
            process(HP);
        }
        // Exit Option:
            if (option == 2)
            printf("Thanks for playing");
    }
}

int main (void)
{
	HP=100; daycount=0; coin=0; bag[0][0]=1; dame = 0;
	srand(time(NULL));
	process (HP);
}

