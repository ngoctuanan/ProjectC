#include "game_functions.h"
void buyWeapon(){
	int choice;
	do{
	     puts("You have chosen to buy a weapon.\n");
		 printf("Your coin: %d\n", coin);
		 puts("1. LongSword: (15 coins to purchase, and it deals 5 damage.) \n"); sleep(2);
		 puts("2. Bow: (10 coins to purchase, and it grants 4 damage.)\n"); sleep(2);
		 puts("3. The dagger (20 coins to buy, deals 7 damage, and has an additional attack effect with a 15% chance.)\n"); sleep(2);
		 puts("0. Nothing"); sleep(2);
		 scanf("%d",&choice);
		 printf ("\e[1;1H\e[2J");
		 switch (choice){
			case 1:
			if(coin >= 15){
				dame += 5;
				coin -= 15; sleep(2);
				printf("You have purchased a longsword, and it deals 5 damage. Your total damage is now: %d",  dame);
			}else {
				sleep(2); puts("I'm sorry, but you don't have enough money to complete the transaction.");
			}
			printf ("\e[1;1H\e[2J");
			break;
	        case 2:	 
			if(coin >= 10){
				dame += 4;
				coin -= 10; sleep(2);
				printf("You choose to buy a wooden bow. It deals 4 damage, and your current total damage is.%d", dame);
			}else{
				sleep(2); puts("I'm sorry, but you don't have enough money to complete the transaction.");
			}
			printf ("\e[1;1H\e[2J");
			break;
		    case 3:
			if(coin >= 20){
				dame += 7;
				coin -= 20; sleep(2);
				printf("You choose to buy the dagger. It deals 4 damage, and your current total damage is.%d", dame);
				int temp;
			}
			printf ("\e[1;1H\e[2J");
			break;
		    case 0:
			    break;
			default:
			      printf("Invalid option. Please try again.\n");
		 }
	     }while (choice != 0); 
}