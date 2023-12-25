#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game_functions.h"

int main (void)
{
	HP=100; daycount=0; coin=0; bag[0][0]=1;
	srand(time(NULL));
	process (HP);
}

