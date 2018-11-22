/*********************************************************************  
** Program Filename: Pack.cpp
** Author: Cassidy Bullock    
** Date: 8/6/2016 
** Description: This is a class for the inventory
** Input: none
** Output: none
*********************************************************************/
#include <iostream>
#include "Pack.h"

using namespace std;

/*********************************************************************  
** Function: Pack
** Description: constructor to set up data
** Parameters: none
** Pre-Conditions: all the values are arbitrary
** Post-Conditions: everything has its proper value
*********************************************************************/
Pack::Pack(){
	milk=0;
	catnip=1;
	yarn=2;
	tuna=3;
	pillow=5;
	fishing_pole=4;
	tiara=6;
	flower_crown=7;
	limit=6;
	amount=0;
	canWin=0;
	for(int i=0; i<8; i++){
		inventory[i]=0;
	}
}

/*********************************************************************  
** Function: printInventory
** Description: will print what is in the pack
** Parameters: none
** Pre-Conditions: player must have asked to see the pack
** Post-Conditions: pack is printed
*********************************************************************/
void Pack::printInventory(){
	cout<<endl;
	cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
	cout<<"%%          PACK          %%"<<endl;
	cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
	if(inventory[milk]==1){
		cout<<"1. Milk"<<endl;
	}
	if(inventory[catnip]==1){
		cout<<"2. Catnip"<<endl;
	}
	if(inventory[yarn]==1){
		cout<<"3. Yarn"<<endl;
	}
	if(inventory[tuna]==1){
		cout<<"4. Tuna"<<endl;
	}
	if(inventory[fishing_pole]==1){
		cout<<"5. Fishing Pole"<<endl;
	}
	if(inventory[pillow]==1){
		cout<<"6. Pillow"<<endl;
	}
	if(inventory[tiara]==1){
		cout<<"7. Tiara"<<endl;
	}
	if(inventory[flower_crown]==1){
		cout<<"8. Flower Crown"<<endl;
	}
}

/*********************************************************************  
** Function: getObj
** Description: puts item in the pack, and will remove item from pack if full
** Parameters: integer representing the object
** Pre-Conditions: item number must be passed
** Post-Conditions: adds object to array using flags
*********************************************************************/
void Pack::getObj(int obj){
	int choice, choice2;
	if(fullPack()==1){
		cout<<endl<<"Your inventory is full. Would you like to drop something?"<<endl;
		cout<<"1. Yes"<<endl;
		cout<<"2. No"<<endl;
		cin>>choice;
		if(choice==1){
			printInventory();
			cout<<"What would you like to remove?"<<endl;
			cout<<"Input CORRECT object number here:";
			cin>>choice2;
			choice2--;
			dropObj(choice2);
		}
		else{
			return;
		}
		inventory[obj]=1;
		amount++;
	}
	else{
		inventory[obj]=1;
		amount++;
	}
	checkCanWin();
}

/*********************************************************************  
** Function: checkCanWin
** Description: checks if the user has the items to win
** Parameters: none
** Pre-Conditions: user must have acquired the correct items
** Post-Conditions: will return true if the player can win
*********************************************************************/
void Pack::checkCanWin(){
	if(inventory[milk]==1 && inventory[catnip]==1 && inventory[yarn]==1 && inventory[tuna]==1){
		canWin=1;
	}
	else{
		canWin=0;
	}
}

/*********************************************************************  
** Function: dropObj
** Description: takes item out of pack
** Parameters: integer representing the object
** Pre-Conditions: item number must be passed
** Post-Conditions: removes object to array using flags
*********************************************************************/
void Pack::dropObj(int obj){
	inventory[obj]=0;
	amount--;
}

/*********************************************************************  
** Function: fullPack
** Description: checks if pack is full
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns true of user has full inventory
*********************************************************************/
bool Pack::fullPack(){
	if(amount>=limit){
		return 1;
	}
	else{
		return 0;
	}
}

/*********************************************************************  
** Function: getCanWin
** Description: returns whether player can win
** Parameters: none
** Pre-Conditions: player must have items
** Post-Conditions: will return if the player can win
*********************************************************************/
bool Pack::getCanWin(){
	checkCanWin();
	return canWin;
}