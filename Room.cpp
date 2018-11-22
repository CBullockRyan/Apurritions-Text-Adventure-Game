/*********************************************************************  
** Program Filename: Room.cpp
** Author: Cassidy Bullock    
** Date: 8/6/2016 
** Description: This is a base class for the rooms
** Input: none
** Output: none
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include "Room.h"

using namespace std;

/*********************************************************************  
** Function: Room
** Description: constructor to set up data
** Parameters: none
** Pre-Conditions: all the values are arbitrary
** Post-Conditions: everything has its proper value
*********************************************************************/
Room::Room(){
	up=NULL;
	down=NULL;
	left=NULL;
	right=NULL;
	kitty=0;
	player=0;
	name="";
}

/*********************************************************************  
** Function: setName
** Description: defines the name
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: sets the name
*********************************************************************/
void Room::setName(string type){
	name=type;
}

/*********************************************************************  
** Function: getName
** Description: returns name
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns name
*********************************************************************/
string Room::getName(){
	return name;
}

/*********************************************************************  
** Function: setPlayer
** Description: defines the whether the player is there or not
** Parameters: bool
** Pre-Conditions: none
** Post-Conditions: sets the player
*********************************************************************/
void Room::setPlayer(bool play){
	player=play;
}

/*********************************************************************  
** Function: getPlayer
** Description: returns player
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns player
*********************************************************************/
bool Room::getPlayer(){
	return player;
}

/*********************************************************************  
** Function: setKitty
** Description: defines the whether the kitty is there or not
** Parameters: bool
** Pre-Conditions: none
** Post-Conditions: sets the kitty
*********************************************************************/
void Room::setKitty(bool cat){
	kitty=cat;
}

/*********************************************************************  
** Function: getKitty
** Description: returns kitty
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns kitty
*********************************************************************/
bool Room::getKitty(){
	return kitty;
}