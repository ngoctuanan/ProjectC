#include "game_functions.h"
void river(int &eventcount)
{
	int blockrepeat[5]={0}, locate=0;
	while (eventcount<6) {
		int temp=rand()%7;
		if (blockrepeat[0]==temp||blockrepeat[1]==temp||blockrepeat[2]==temp||blockrepeat[3]==temp) continue;
		blockrepeat[locate]=temp; locate++;
		if (temp==1) merchant(eventcount);
		if (temp==2) merchant(eventcount);
		if (temp==3) merchant(eventcount);
		if (temp==4) merchant(eventcount);
		if (temp==5) merchant(eventcount);
		if (temp==6) merchant(eventcount);
		if (HP==0) break;
	}
}
