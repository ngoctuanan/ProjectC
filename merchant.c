#include "game_functions.h"
void merchant(int &eventcount){
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