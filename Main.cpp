/*********************************************************************  
** Program Filename: Main.cpp
** Author: Cassidy Bullock    
** Date: 8/6/2016  
** Description: This program runs the game Apurrrritions, where the
**				player must find a cat in a haunted house.
** Input: none
** Output: none
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include "Room.h"
#include "Haunted.h"
#include "Temporary.h"
#include "Regular.h"
#include "Pack.h"

using namespace std;

/*********************************************************************  
** Function: setPtrs
** Description: sets up the pointers for all the nodes
** Parameters: each node, and a string for the name
** Pre-Conditions: pointers are NULL
** Post-Conditions: pointers are pointing at specific other nodes
*********************************************************************/
void setPtrs(Room *prime, Room *up, Room *down, Room *left, Room *right, string type){
	prime->left=left;
	prime->right=right;
	prime->up=up;
	prime->down=down;
	prime->setName(type);
}

/*********************************************************************  
** Function: generateKitty
** Description: puts the cat in a new room of the house
** Parameters: every room except the dining room
** Pre-Conditions: kitty may or may not already be in the one of the rooms
** Post-Conditions: kitty will be put in an arbitrary room
*********************************************************************/
void generateKitty(Room *living, Room *kitchen, Room *bedroom, Room *bathroom){
	int where=rand()%4;
	if(where==0){
		living->setKitty(1);
		kitchen->setKitty(0);
		bedroom->setKitty(0);
		bathroom->setKitty(0);
	}
	else if(where==1){
		living->setKitty(0);
		kitchen->setKitty(1);
		bedroom->setKitty(0);
		bathroom->setKitty(0);
	}
	else if(where==2){
		living->setKitty(0);
		kitchen->setKitty(0);
		bedroom->setKitty(1);
		bathroom->setKitty(0);
	}
	else if(where==3){
		living->setKitty(0);
		kitchen->setKitty(0);
		bedroom->setKitty(0);
		bathroom->setKitty(1);
	}
}

/*********************************************************************  
** Function: setUp
** Description: establishes the game
** Parameters: every room
** Pre-Conditions: nothing has happened yet
** Post-Conditions: generates the cat, sets the player in the dining
**					room and prints instructions to user
*********************************************************************/
void setUp(Room *dining, Room *living, Room *kitchen, Room *bedroom, Room *bathroom){
	generateKitty(living, kitchen, bedroom, bathroom);
	dining->setPlayer(1);
	cout<<"Welcome to Apurrrritions."<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"Your little sister has lost her cat in a haunted house."<<endl;
	cout<<"You must venture in and find it. Avoid getting killed by"<<endl;
	cout<<"ghosts and try and find where the cat went. Certain objects"<<endl;
	cout<<"will help you win the game. But be careful, some of the rooms"<<endl;
	cout<<"are haunted, while others will just disappear."<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"You enter the house and find yourself in the dining room."<<endl;
}

/*********************************************************************  
** Function: printTimer
** Description: displays how many moves the user has left
** Parameters: the counter
** Pre-Conditions: looks at what the counter is at
** Post-Conditions: tells user how many moves are left
*********************************************************************/
void printTimer(int ctr){
	cout<<endl;
	cout<<"**********************************"<<endl;
	cout<<"**********************************"<<endl;
	cout<<"****     MOVES LEFT: "<<20-ctr<<"       ****"<<endl;
	cout<<"**********************************"<<endl;
	cout<<"**********************************"<<endl;
}

/*********************************************************************  
** Function: managePack
** Description: displays pack and gives user options
** Parameters: the pack
** Pre-Conditions: user must ask to open the pack
** Post-Conditions: user sees what is in the pack, and can drop items
*********************************************************************/
void managePack(Pack &pack){
	int first, second;
	pack.printInventory();
	while(first!=2){
		cout<<"Would you like to:"<<endl;
		cout<<" 1. Drop something "<<endl;
		cout<<" 2. Quit"<<endl;
		cin>>first;
		if(first==1){
			cout<<"Which would you like to drop?"<<endl; 
			cout<<"Input the CORRECT number for the item here: ";
			cin>>second;
			second--;
			pack.dropObj(second);
		}
	}
}

/*********************************************************************  
** Function: printMenu
** Description: prints the users options
** Parameters: the pack
** Pre-Conditions: user must be ready to move out of a room
** Post-Conditions: user can choose to look at the pack, move rooms,
**					or get information
*********************************************************************/
int printMenu(Pack &pack){
	int choice;
	while(choice!=4 && choice!=3 && choice!=5 && choice!=6){
		cout<<endl<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"~~  What would you like to do?     ~~"<<endl;
		cout<<"~~  1. Open your pack              ~~"<<endl;
		cout<<"~~  2. Call the kitty              ~~"<<endl;
		cout<<"~~  3. Go North                    ~~"<<endl;
		cout<<"~~  4. Go South                    ~~"<<endl;
		cout<<"~~  5. Go East                     ~~"<<endl;
		cout<<"~~  6. Go West                     ~~"<<endl;
		cout<<"~~  7. Hint to win game            ~~"<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"CHOICE: ";
		cin>>choice;
		while(choice<1 || choice>7){
			if(cin.fail()){
				cout<<"You have not entered a valid input. Please try again: ";
				cin>>choice;
			}
			else{
				cout<<"You have not entered a valid input. Please try again: ";
				cin>>choice;
			}
		}
		if(choice==1){
			managePack(pack);
		}
		else if(choice==2){
			cout<<endl<<"You quietly call in a sing-song voice 'Here kitty-kitty-kitty...' "<<endl;
			cout<<"You hear some far away scratching and perhaps a quiet meow but you can't be sure."<<endl;
		}
		else if(choice==7){
			cout<<"This is how to win the game:"<<endl;
			cout<<"1. You must be in the same room as the cat."<<endl;
			cout<<"2. You must have the milk, tuna, catnip, and yarn in your pack."<<endl;
		}
	}
	return choice;
}

/*********************************************************************  
** Function: checkWin
** Description: checks whether the user has won
** Parameters: current room, win flag, the pack
** Pre-Conditions: user has just entered a new room
** Post-Conditions: if the player has all the objects and the cat is
**					in the room, will return true
*********************************************************************/
bool checkWin(Room *current, bool &win, Pack &pack){
	if(current->getKitty()==1){
		if(pack.getCanWin()==1){
			win=1;
		}
		else{
			win=0;
		}
	}
	else{
		win=0;
	}
	return win;
}

/*********************************************************************  
** Function: changeRoom
** Description: changes where the user is and is responsible for the
**				temporary nodes.
** Parameters: every room, the direction, current location, and pack
** Pre-Conditions: the user must have specified where to go next
** Post-Conditions: will change rooms, but if the user goes somewhere
**					with a null pointer, a new room will be created
**					then deleted when the user exits the room.
*********************************************************************/
void changeRoom(Room *dining, Room *living, Room *kitchen, Room *bedroom, Room *bathroom, int direction, int current_loc, Pack &pack){
	if(current_loc==1){
		dining->setPlayer(0);
		if(direction==3){
			if(dining->up==NULL){
				dining->up=new Temporary;
				dining->up->run(pack);
				dining->up=NULL;
				dining->setPlayer(1);
			}
			else{
				dining->up->setPlayer(1);
			}
		}										
		else if(direction==4){	
			dining->down->setPlayer(1);		
		}										
		else if(direction==5){
			dining->right->setPlayer(1);
		}
		else if(direction==6){
			dining->left->setPlayer(1);
		}
	}
	else if(current_loc==2){
		living->setPlayer(0);
		if(direction==3){
			living->up->setPlayer(1);
		}
		else if(direction==4){
			living->down->setPlayer(1);
		}
		else if(direction==5){
			if(living->right==NULL){
				living->right=new Temporary;
				living->right->run(pack);
				living->right=NULL;
				living->setPlayer(1);
			}
			else{
				living->right->setPlayer(1);
			}
		}
		else if(direction==6){
			living->left->setPlayer(1);
		}
	}
	else if(current_loc==3){
		kitchen->setPlayer(0);
		if(direction==3){
			kitchen->up->setPlayer(1);
		}
		else if(direction==4){
			kitchen->down->setPlayer(1);
		}
		else if(direction==5){
			kitchen->right->setPlayer(1);
		}
		else if(direction==6){
			kitchen->left->setPlayer(1);
		}
	}
	else if(current_loc==4){
		bedroom->setPlayer(0);
		if(direction==3){
			bedroom->up->setPlayer(1);
		}
		else if(direction==4){
			if(bedroom->down==NULL){
				bedroom->down=new Temporary;
				bedroom->down->run(pack);
				bedroom->down=NULL;
				bedroom->setPlayer(1);
			}
			else{
				bedroom->down->setPlayer(1);
			}
		}
		else if(direction==5){
			bedroom->right->setPlayer(1);
		}
		else if(direction==6){
			bedroom->left->setPlayer(1);
		}
	}
	else if(current_loc==5){
		bathroom->setPlayer(0);
		if(direction==3){
			bathroom->up->setPlayer(1);
		}
		else if(direction==4){
			bathroom->down->setPlayer(1);
		}
		else if(direction==5){
			bathroom->right->setPlayer(1);
		}
		else if(direction==6){
			if(bathroom->left==NULL){
				bathroom->left=new Temporary;
				bathroom->left->run(pack);
				bathroom->left=NULL;
				bathroom->setPlayer(1);
			}
			else{
				bathroom->left->setPlayer(1);
			}
		}
	}
}

/*********************************************************************  
** Function: moveKitty
** Description: arbitrarily moves the cat
** Parameters: all the rooms
** Pre-Conditions: this will happen at the beginning of a turn
** Post-Conditions: kitty has a 25% chance of changing rooms
*********************************************************************/
void moveKitty(Room *dining, Room *living, Room *kitchen, Room *bedroom, Room *bathroom){
	int move=rand()%4;
	if(move==0){
		generateKitty(living, kitchen, bedroom, bathroom);
	}
}

/*********************************************************************  
** Function: run
** Description: this is in charge of running the program, it will run
**				the various room simulations and keep track of whether
**				the player has won or lost
** Parameters: damage
** Pre-Conditions: gets called by main to do all of the work
** Post-Conditions: will run until player has either won or lost
*********************************************************************/
void run(Room *dining, Room *living, Room *kitchen, Room *bedroom, Room *bathroom, int &ctr, bool &win, Pack &pack){
	int direction, current_loc;
	bool alive;
	setUp(dining, living, kitchen, bedroom, bathroom);
	for(ctr=0; ctr<20; ctr++){
		printTimer(ctr);
		moveKitty(dining, living, kitchen, bedroom, bathroom);
		if(dining->getPlayer()==1){
			if(checkWin(dining, win, pack)==0){
				alive=dining->run(pack);
				current_loc=1;
			}
			else{
				win=1;
			}
		}
		else if(living->getPlayer()==1){
			if(checkWin(living, win, pack)==0){
				alive=living->run(pack);
				current_loc=2;
			}
			else{
				win=1;
			}
		}
		else if(kitchen->getPlayer()==1){
			if(checkWin(kitchen, win, pack)==0){
				alive=kitchen->run(pack);
				current_loc=3;
			}
			else{
				win=1;
			}
		}
		else if(bedroom->getPlayer()==1){
			if(checkWin(bedroom, win, pack)==0){
				alive=bedroom->run(pack);
				current_loc=4;
			}
			else{
				win=1;
			}
		}
		else if(bathroom->getPlayer()==1){
			if(checkWin(bathroom, win, pack)==0){
				alive=bathroom->run(pack);
				current_loc=5;
			}
			else{
				win=1;
			}
		}
		else{
			cout<<"Something has gone wrong. Quitting."<<endl;
			return;
		}
		if(win==1){
			return;
		}
		else if(alive==0){
			return;
		}
		direction=printMenu(pack);
		changeRoom(dining, living, kitchen, bedroom, bathroom, direction, current_loc, pack);
	}
	win=0;
}

int main(){
	srand(time(NULL));
	bool win=0;
	int ctr;
	Pack pack;
	Haunted bed;
	Haunted kitch;
	Regular dinin;
	Regular livin;
	Haunted bath;
	Room *dining=&dinin;
	Room *living=&livin;
	Room *kitchen=&kitch;
	Room *bedroom=&bed;
	Room *bathroom=&bath;
	setPtrs(kitchen, dining, bedroom, bathroom, living, "Kitchen");
	setPtrs(dining, NULL, kitchen, bathroom, living, "Dining Room");
	setPtrs(living, dining, bedroom, kitchen, NULL, "Living Room");
	setPtrs(bedroom, kitchen, NULL, bathroom, living, "Bedroom");
	setPtrs(bathroom, dining, bedroom, NULL, kitchen, "Bathroom");
	run(dining, living, kitchen, bedroom, bathroom, ctr, win, pack);
	if(win==1){
		cout<<"You have entered the same room as the kitty."<<endl;
		cout<<"You check your pack and pull out the milk, tuna, catnip, and yarn."<<endl;
		cout<<"The kitty accepts your offerings and gets close enough for you to grab."<<endl;
		cout<<"You pick up the kitty and make your way out of the haunted house."<<endl;
		cout<<"Your sister is overjoyed to have her cat returned. Congratulations. You win."<<endl;
	}
	else if(ctr==20){
		cout<<"Unfortunately, you have taken too long to find the cat. Your sister has started crying and you lose the game."<<endl;
	}
	else{
		cout<<"You have been eliminated by the ghosts. You are dead and your sister never got her cat back. You lose the game."<<endl;
	}
	return 0;
}

//CODE TO PRINT OUT WHERE THE POINTERS ARE POINTING
	
	/* cout<<"KITCHEN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"ABOVE: "<<kitchen->up->getName()<<endl;
	cout<<"RIGHT: "<<kitchen->right->getName()<<endl;
	cout<<"BELOW: "<<kitchen->down->getName()<<endl;
	cout<<"LEFT: "<<kitchen->left->getName()<<endl;
	cout<<"DINING ROOM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	//cout<<"ABOVE: "<<dining->up->getName()<<endl;
	cout<<"RIGHT: "<<dining->right->getName()<<endl;
	cout<<"BELOW: "<<dining->down->getName()<<endl;
	cout<<"LEFT: "<<dining->left->getName()<<endl;
	cout<<"LIVING ROOM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"ABOVE: "<<living->up->getName()<<endl;
	//cout<<"RIGHT: "<<living->right->getName()<<endl;
	cout<<"BELOW: "<<living->down->getName()<<endl;
	cout<<"LEFT: "<<living->left->getName()<<endl;
	cout<<"BEDROOM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"ABOVE: "<<bedroom->up->getName()<<endl;
	cout<<"RIGHT: "<<bedroom->right->getName()<<endl;
	//cout<<"BELOW: "<<bedroom->down->getName()<<endl;
	cout<<"LEFT: "<<bedroom->left->getName()<<endl;
	cout<<"BATHROOM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"ABOVE: "<<bathroom->up->getName()<<endl;
	cout<<"RIGHT: "<<bathroom->right->getName()<<endl;
	cout<<"BELOW: "<<bathroom->down->getName()<<endl;
	//cout<<"LEFT: "<<bathroom->left->getName()<<endl; */