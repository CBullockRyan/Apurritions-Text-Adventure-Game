#ifndef HAUNTED_H
#define HAUNTED_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Room.h"
#include "Pack.h"

using namespace std;

class Haunted: public Room{
	public:
		bool special(Pack&);
		bool run(Pack&);
		bool scenario1(Pack&);
		bool scenario2(Pack&);
		bool scenario3(Pack&);
};

#endif