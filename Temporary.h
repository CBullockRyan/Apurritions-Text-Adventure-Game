#ifndef TEMPORARY_H
#define TEMPORARY_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Room.h"
#include "Pack.h"

using namespace std;

class Temporary: public Room{
	public:
		bool special(Pack&);
		bool run(Pack&);
};

#endif