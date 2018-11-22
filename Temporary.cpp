/*********************************************************************  
** Program Filename: Temporary.cpp
** Author: Cassidy Bullock    
** Date: 8/6/2016 
** Description: This is a class for the temporary rooms
** Input: none
** Output: none
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include "Room.h"
#include "Temporary.h"
#include "Pack.h"

using namespace std;

/*********************************************************************  
** Function: run
** Description: runs the simulation of being in a disappearing room
** Parameters: the pack
** Pre-Conditions: player must have gone "off the map" so to speak
** Post-Conditions: player will temporarily be in this room
*********************************************************************/
bool Temporary::run(Pack &pack){
	int choice;
	cout<<"You have entered a disappearing room. There are several objects on the floor but ";
	cout<<"since the room is disappearing you only have time to grab one."<<endl;
	cout<<"1. Tiara"<<endl;
	cout<<"2. Catnip"<<endl;
	cout<<"3. Nothing"<<endl;
	cin>>choice;
	special(pack);
	if(choice==1){
		pack.getObj(6);
		cout<<"You have picked up the tiara"<<endl;
	}
	else if(choice==2){
		pack.getObj(1);
		cout<<"You have picked up the catnip"<<endl;
	}
	else{
		return 0;
	}
}

/*********************************************************************  
** Function: special
** Description: has a 5% chance of the player losing their inventory
** Parameters: pack
** Pre-Conditions: happens before player has picked up the new item
** Post-Conditions: player loses everything
*********************************************************************/
bool Temporary::special(Pack &pack){
	int spill=rand()%20;
	if(spill==2){
		cout<<"As you were rushing out of the disappearing room, you dropped your pack. ";
		cout<<"You have lost everything in your inventory except the thing you picked up."<<endl;
		for(int i=0; i<8; i++){
			pack.dropObj(i);
		}
	}
}