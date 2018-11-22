/*********************************************************************  
** Program Filename: Haunted.cpp
** Author: Cassidy Bullock    
** Date: 8/6/2016 
** Description: This is a class for the haunted rooms
** Input: none
** Output: none
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include "Room.h"
#include "Haunted.h"
#include "Pack.h"

using namespace std;

/*********************************************************************  
** Function: scenario1
** Description: runs the simulation of being in the kitchen
** Parameters: the pack
** Pre-Conditions: player must be in the room
** Post-Conditions: player can obtain objects or leave
*********************************************************************/
bool Haunted::scenario1(Pack &pack){
	bool alive;
	cout<<"The kitchen could have been pulled directly from a '50s magazine, except for the cobwebs everywhere. ";
	cout<<"You look around the room but there doesn't appear to be anything of worth here.";
	cout<<"Just as you think about exitting the room a chill involunarily shoots through your body";
	cout<<" as a ghost passes through you. You watch as the ghost pulls out some dice and a knife.";
	cout<<" 'Would you like to play a game with me?' the ghost asks you politely."<<endl;
	cout<<"Eyeing the knife, you find you can't refuse."<<endl;
	alive=special(pack);
	return alive;
}

/*********************************************************************  
** Function: scenario2
** Description: runs the simulation of being in the bedroom
** Parameters: the pack
** Pre-Conditions: player must be in the room
** Post-Conditions: player can obtain objects or leave
*********************************************************************/
bool Haunted::scenario2(Pack &pack){
	bool alive;
	int choice;
	cout<<"This bedroom is very obviously occupied by a ghost. It sleeps on the bed clutching a pillow.";
	cout<<" You take a step and the floor creaks, the ghost awakens and seems fairly disgruntled."<<endl;
	cout<<" The ghost makes to whack you with the pillow when through the wall appears another ghost."<<endl;
	cout<<" 'Oh dear, not again. Jack, it is rude to hit guests.' The ghost turns to you.";
	cout<<" 'I must apologize for my brother. Would you like to play a game with us to make up for it?'"<<endl;
	cout<<"1. Yes"<<endl;
	cout<<"2. No"<<endl;
	cin>>choice;
	if(choice==1){
		alive=special(pack);
	}
	else{
		alive=1;
	}
	return alive;
}

/*********************************************************************  
** Function: scenario3
** Description: runs the simulation of being in the bathroom
** Parameters: the pack
** Pre-Conditions: player must be in the room
** Post-Conditions: player can obtain objects or leave
*********************************************************************/
bool Haunted::scenario3(Pack &pack){
	bool alive;
	int choice;
	cout<<"As you enter the bathroom you see a ghost wearing a sundress and a flower crown. ";
	cout<<"She looks at herself in the mirror although there is no reflection. "<<endl;
	cout<<"Suddenly she turns to you and says 'Would you like my flower crown? You can win it from me.' "<<endl;
	cout<<"1. Play"<<endl;
	cout<<"2. Leave"<<endl;
	cin>>choice;
	if(choice==1){
		alive=special(pack);
	}
	else{
		alive=1;
	}
	return alive;
}

/*********************************************************************  
** Function: run
** Description: runs the simulation of being in a haunted room
** Parameters: the pack
** Pre-Conditions: player must be in the room
** Post-Conditions: player will interact based on which room their in
*********************************************************************/
bool Haunted::run(Pack &pack){
	bool alive;
	cout<<"You have now entered the "<<name<<endl;
	if(getKitty()==1){
		cout<<"You see the kitty is in the room with you."<<endl;
		cout<<"You try to catch it but it alludes you."<<endl;
	}
	else{
		cout<<"You cannot see the kitty in this room."<<endl;
	}
	cout<<"This room seems to have an otherwordly presence."<<endl;
	if(name=="Kitchen"){
		alive=scenario1(pack);
	}
	else if(name=="Bedroom"){
		alive=scenario2(pack);
	}
	else if(name=="Bathroom"){
		alive=scenario3(pack);
	}
	return alive;
}

/*********************************************************************  
** Function: special
** Description: simulates a dice game with ghosts
** Parameters: the pack
** Pre-Conditions: player must be in the room
** Post-Conditions: player could receive an object or die
*********************************************************************/
bool Haunted::special(Pack &pack){
	bool alive;
	int choice, choice2;
	int ghost_sum=0;
	int player_sum=0;
	cout<<"You have entered into the ghost's game. The ghost will roll 2 dice with 6 sides. ";
	cout<<"You have 3 options:"<<endl;
	cout<<"1. Roll 3 dice with 4 sides"<<endl;
	cout<<"2. Roll 2 dice with 6 sides"<<endl;
	cout<<"3. Roll 1 dice with 12 sides"<<endl;
	cout<<"If you roll higher than the ghost, you will receive an item."<<endl;
	cout<<"If you roll the same number as the ghost, the ghost will kill you."<<endl;
	cout<<"If you roll lower than the ghost nothing happens and you may leave."<<endl;
	cout<<"CHOICE: ";
	cin>>choice;
	for(int i=0; i<2; i++){
		ghost_sum=ghost_sum+(rand()%6+1);
	}
	cout<<"The ghost has rolled a "<<ghost_sum<<endl;
	if(choice==1){
		for(int i=0; i<3; i++){
			player_sum=player_sum+(rand()%4+1);
		}
	}
	else if(choice==2){
		for(int i=0; i<2; i++){
			player_sum=player_sum+(rand()%6+1);
		}
	}
	else if(choice==3){
		player_sum=rand()%12+1;
	}
	cout<<"You have rolled a "<<player_sum<<endl;
	if(player_sum==ghost_sum){
		alive=0;
	}
	else if(player_sum<ghost_sum){
		cout<<"You will be permitted to leave."<<endl;
		alive=1;
	}
	else{
		if(name=="Kitchen"){
			cout<<"The ghost is offering you a jug of milk. Would you like to take it?"<<endl;
			cout<<"1. Yes"<<endl;
			cout<<"2. No"<<endl;
			cin>>choice2;
			if(choice2==1){
				pack.getObj(0);
			}
		}
		else if(name=="Bedroom"){
			cout<<"The ghost is offering you a pillow. Would you like to take it?"<<endl;
			cout<<"1. Yes"<<endl;
			cout<<"2. No"<<endl;
			cin>>choice2;
			if(choice2==1){
				pack.getObj(5);
			}
		}
		else if(name=="Bathroom"){
			cout<<"The ghost is offering you a flower crown. Would you like to take it?"<<endl;
			cout<<"1. Yes"<<endl;
			cout<<"2. No"<<endl;
			cin>>choice2;
			if(choice2==1){
				pack.getObj(7);
			}
		}
	alive=1;
	}
	return alive;
}