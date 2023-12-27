#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <time.h>


extern int HP, coin, bag[4][100], dame, daycount;

void buyWeapon();
void equipment();
void food();
void material();
void goods(int enemyHP);
void openbag(int &enemyHP);
void snake(int &HP);
void bat(int &HP);
void bear(int &HP);
void berrybushevent(int &eventcount);
void dangerforest(int &eventcount);
void dayloop(int &daycount);
void fishermanevent(int &eventcount);
void forest(int &eventcount);
void fruitbasket(int &eventcount);
void gianttree(int &eventcount);
void merchant(int &eventcount);
void monkey(int &HP);
void process(int &HP);
void rat(int &HP);
void restblurwaterevent(int &eventcount);
void river(int &eventcount);
void startday(int &eventcount);
void thief(int &HP);
void waterfall(int &eventcount);
void wolf(int &HP);

#endif
