#ifndef REGULAR_H
#define REGULAR_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Room.h"
#include "Pack.h"

using namespace std;

class Regular: public Room{
	public:
		bool special(Pack&);
		bool run(Pack&);
		void scenario1(Pack&);
		void scenario2(Pack&);
};

#endif