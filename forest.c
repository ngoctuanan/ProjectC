#include "game_functions.h"
void forest(int &eventcount)
{
	int blockrepeat[2]={0}, locate=0;
	while (eventcount<2) {
		int temp=rand()%2+1;
		if (blockrepeat[0]==temp||blockrepeat[1]==temp) continue;
		blockrepeat[locate]=temp; locate++;
		if (temp==1) gianttree (eventcount);
		if (temp==2) dangerforest (eventcount);
		if (HP==0) break;
	}
}