#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Pack.h"

using namespace std;

struct Room{
	public:	
		struct Room *left;
		struct Room *right;
		struct Room *up;
		struct Room *down;
		virtual bool special(Pack&)=0;
		virtual bool run(Pack&)=0;
		void setName(string);
		string getName();
		void setPlayer(bool);
		bool getPlayer();
		void setKitty(bool);
		bool getKitty();
		Room();
	protected:
		bool kitty;
		bool player;
		string name;
};

#endif