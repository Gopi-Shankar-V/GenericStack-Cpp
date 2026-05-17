#include "header.h"

template <class Topt>
void opt1(Topt &obj){
	int op, c = 0;
	pf << GREEN << "		Integer Stack Application Ready To Use!" << endl<< endl;
	pf << "		(1) PUSH	(2)POP		(3)PEAK		(4)DISPLAY	(5)MAIN MENU" << RESET << endl;
	pf << blue_b << "	Enter Your Choice" << WHITE_BB << "$ " << RESET ;
	sf >> op;

	switch(op){
		case 1: push(obj);
			break;
		case 2: //pop();
			break;
		case 3: //peak();
			break;
		case 4: //display();
			break;
		case 5: ;
			
		default: 
			switch(++c){
				case 1: pf << red_bb <<"	Invalid Input!" << RESET << endl;
					pf << YELLOW_B <<"	Please read the option carefully..." << RESET << endl << endl;
					break;
					
				case 2: pf << red_bb <<"	Invalid Input!" << RESET << endl;
					pf << YELLOW_B <<"	Last chance please take care..." << RESET << endl << endl;
					break;
				case 3: pf << red_bb <<"	Invalid Input!" << RESET << endl;
					pf << YELLOW_B <<"	Try again later." << RESET << endl << endl;
					exit(0);
				}
		}
}
