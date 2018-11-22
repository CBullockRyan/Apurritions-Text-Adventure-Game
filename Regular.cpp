/*********************************************************************  
** Program Filename: Regular.cpp
** Author: Cassidy Bullock    
** Date: 8/6/2016 
** Description: This is a class for the regular rooms
** Input: none
** Output: none
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include "Room.h"
#include "Regular.h"
#include "Pack.h"

using namespace std;

/*********************************************************************  
** Function: run
** Description: runs the simulation of being in a regular room
** Parameters: the pack
** Pre-Conditions: player must be in the room
** Post-Conditions: player will interact based on which room their in
*********************************************************************/
bool Regular::run(Pack &pack){
	cout<<"You have now entered the "<<name<<endl;
	if(getKitty()==1){
		cout<<"You see the kitty is in the room with you."<<endl;
		cout<<"You try to catch it but it alludes you."<<endl;
	}
	else{
		cout<<"You cannot see the kitty in this room."<<endl;
	}
	cout<<"This room does not appear to be haunted."<<endl;
	if(name=="Dining Room"){
		scenario1(pack);
	}
	else if(name=="Living Room"){
		scenario2(pack);
	}
	return 1;
}

/*********************************************************************  
** Function: scenario1
** Description: runs the simulation of being in the dining room
** Parameters: the pack
** Pre-Conditions: player must be in the room
** Post-Conditions: player can obtain objects or leave
*********************************************************************/
void Regular::scenario1(Pack &pack){
	int choice, choice2;
	cout<<"The dining room is strangely fishing themed. It might make sense to find a cat here. ";
	cout<<"You see four doors, one on each wall. You see a table in the middle of the room with a fishing display. ";
	while(choice!=2){
		cout<<"Would you like to:"<<endl;
		cout<<"1. Inspect the fishing display"<<endl;
		cout<<"2. Leave this room"<<endl;
		cin>>choice;
		if(choice==1){
			cout<<"You inspect the fishing display. There is a fishing pole and some fresh tuna on a dish. ";
			cout<<"It looks like something may have eaten the tuna before.";
			cout<<" You also notice a small scrap of paper."<<endl;
			while(choice2!=4){
				cout<<"1. Pick up the fishing pole"<<endl;
				cout<<"2. Pick up the tuna"<<endl;
				cout<<"3. Inspect the scrap of paper"<<endl;
				cout<<"4. Exit the display"<<endl;
				cin>>choice2;
				if(choice2==1){
					pack.getObj(4);
					cout<<"You have picked up the fishing pole."<<endl;
				}
				else if(choice2==2){
					pack.getObj(3);
					cout<<"You have picked up the tuna."<<endl;
				}
				else if(choice2==3){
					special(pack);
				}
			}
		}
	}
}

/*********************************************************************  
** Function: scenario2
** Description: runs the simulation of being in the living room
** Parameters: the pack
** Pre-Conditions: player must be in the room
** Post-Conditions: player can obtain objects or leave
*********************************************************************/
void Regular::scenario2(Pack &pack){
	int choice, choice2;
	bool out=0;
	cout<<"The living room reminds you of your grandmother's house. There is a door on each wall. ";
	cout<<"There is an old black and white television running static across the screen. The antenna look broken. ";
	cout<<"There is an old pink scratchy sofa with some knitting needles and yarn on it. This seems like a room a cat would like. ";
	cout<<"Occasionally you hear some sort of voice coming from the TV but there are no discernable words. ";
	cout<<"This room is not a pleasant place to be. You try each door but they are locked.";
	while(out==0){
		cout<<"Would you like to: "<<endl;
		cout<<"1. Sit on the sofa"<<endl;
		cout<<"2. Inspect the TV"<<endl;
		cin>>choice;
		if(choice==1){
			cout<<"You notice some paper on the sofa."<<endl;
			while(choice2!=3){
				cout<<"1. Pick up the yarn"<<endl;
				cout<<"2. Inspect the paper"<<endl;
				cout<<"3. Get off the sofa"<<endl;
				cin>>choice2;
				if(choice2==1){
					pack.getObj(2);
					cout<<"You have picked up the yarn."<<endl;
				}
				else if(choice2==2){
					special(pack);
				}
			}
			choice2=0;
		}
		else if(choice==2){
			cout<<"Getting closer to the TV the static sounds like purring. The words that";
			cout<<" the voice are saying become more discernable. The words are something like 'Good kitty cat'";
			cout<<" The voice sounds like your little sisters. With a shutter you unplug the TV.";
			cout<<" The TV vanishes and so does the sofa with the knitting stuff. All of the doors swing open."<<endl;
			out=1;
		}
	}
}

/*********************************************************************  
** Function: special
** Description: gives a random helpful fact about gameplay
** Parameters: the pack
** Pre-Conditions: player must be in the room
** Post-Conditions: player must have opted for the hint
*********************************************************************/
bool Regular::special(Pack &pack){
	int fact=rand()%9;
	if(fact==0){
		cout<<"The torn piece of paper says: ' cats cannot be found in dining rooms ' "<<endl;
	}
	else if(fact==1){
		cout<<"The torn piece of paper says: ' objects can be found in any room ' "<<endl;
	}
	else if(fact==2){
		cout<<"The torn piece of paper says: ' the kitchen is the center. To go north is to dine. To go south is to sleep. To go west is to bathe. To go east is to live. ' "<<endl;
	}
	else if(fact==3){
		cout<<"The torn piece of paper says: ' the dining room is where you begin. To go north is to disappear. To go south is to provide. To go west is to bathe. To go east is to live. ' "<<endl;
	}
	else if(fact==4){
		cout<<"The torn piece of paper says: ' ghosts like to bathe, sleep, and cook. '"<<endl;
	}
	else if(fact==5){
		cout<<"The torn piece of paper says: ' the living room is where you knit. To go north is to dine. To go south is to sleep. To go west is to provide. To go east is to disappear. ' "<<endl;
	}
	else if(fact==6){
		cout<<"The torn piece of paper says: ' the bedroom is where you sleep. To go north is to provide. To go south is to disappear. To go west is to bathe. To go east is to live. ' "<<endl;
	}
	else if(fact==7){
		cout<<"The torn piece of paper says: ' the bathroom is where you bathe. To go north is to dine. To go south is to sleep. To go west is to disappear. To go east is to provide. ' "<<endl;
	}
	else if(fact==8){
		cout<<"In disappearing rooms, there is a 5% chance you will lose all your inventory."<<endl;
	}
	return 0;
}