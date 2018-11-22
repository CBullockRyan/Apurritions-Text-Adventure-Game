#ifndef PACK_H
#define PACK_H

#include <iostream>
#include <string>

using namespace std;

class Pack{
	protected:
		int milk;
		int catnip;
		int yarn;
		int tuna;
		int pillow;
		int fishing_pole;
		int tiara;
		int flower_crown;
		int limit;
		int amount;
		bool inventory[8];
		bool canWin;
	public:
		Pack();
		void getObj(int);
		void dropObj(int);
		bool fullPack();
		void printInventory();
		void checkCanWin();
		bool getCanWin();
};

#endif