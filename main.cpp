#include <iostream>
#include <fstream>
using namespace std;

#define pf cout
#define sf cin
#define max 5

// dark foreground(font) colours
#define BLACK "\033[30m"
#define BLACK_B "\033[30;1m"
#define BLACK_BB "\033[30;1;5m"

#define RED "\033[31m"
#define RED_B "\033[31;1m"
#define RED_BB "\033[31;1;5m"

#define GREEN "\033[32m"
#define GREEN_B "\033[32;1m"
#define GREEN_BB "\033[32;1;5m"

#define YELLOW "\033[33m"
#define YELLOW_B "\033[33;1m"
#define YELLOW_BB "\033[33;1;5m"

#define BLUE "\033[34m"
#define BLUE_B "\033[34;1m"
#define BLUE_BB "\033[34;1;5m"

#define MEGENTA "\033[35m"
#define MEGENTA_B "\033[35;1m"
#define MEGENTA_BB "\033[35;1;5m"

#define CYAN "\033[36m"
#define CYAN_B "\033[36;1m"
#define CYAN_BB "\033[36;1;5m"

#define WHITE "\033[37m"
#define WHITE_B "\033[37;1m"
#define WHITE_BB "\033[37;1;5m"

// bright foreground(font) colours
#define black "\033[90m"
#define black_b "\033[90;1m"
#define black_bb "\033[90;1;5m"

#define red "\033[91m"
#define red_b "\033[91;1m"
#define red_bb "\033[91;1;5m"

#define green "\033[92m"
#define green_b "\033[92;1m"
#define green_bb "\033[92;1;5m"

#define yellow "\033[93m"
#define yellow_b "\033[93;1m"
#define yellow_bb "\033[93;1;5m"

#define blue "\033[94m"
#define blue_b "\033[94;1m"
#define blue_bb "\033[94;1;5m"

#define megenta "\033[95m"
#define megenta_b "\033[95;1m"
#define megenta_bb "\033[95;1;5m"

#define cyan "\033[96m"
#define cyan_b "\033[96;1m"
#define cyan_bb "\033[96;1;5m"

#define white "\033[97m"
#define white_b "\033[97;1m"
#define white_bb "\033[97;1;5m"

#define RESET "\033[0m"

template <class Type>
class stack{
	public:
	Type stk[max];
	static int TOP, count;
	stack(){
		TOP = -1;
	}
};

template <class Type>
int stack<Type> :: TOP;

template <class Type>
int stack<Type> :: count;

template <class Tpush>
void push(Tpush &);

template <class Tpop>
void pop(Tpop &);

template <class Tpeek>
void peek(Tpeek &);

template <class Tdisplay>
void display(Tdisplay &);

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

template <class Topt>
void opt(Topt &obj){
	int op, c = 0;
	while(1){
		pf << GREEN_B << "		(1) PUSH	(2)POP		(3)Peek		(4)DISPLAY	(5)MAIN MENU" << RESET << endl << endl;
		pf << blue_b << "	Enter Your Choice" << WHITE_BB << "$ " << RESET ;
		sf >> op;

		switch(op){
			case 1: push(obj);
				break;
			case 2: pop(obj);
				break;
			case 3: peek(obj);
				break;
			case 4: display(obj);
				break;
			case 5: return;
				
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
}	

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PUSH >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
template <class Tpush>
void push(Tpush &obj){
	  
	if(obj.TOP > max){
		pf << YELLOW_BB << "		Stack Overflow!" << RESET << endl;
		return;
	}
	pf << "		" << BLUE_B "Enter the data" << WHITE_BB << "$ " << RESET;
	sf >> obj.stk[++obj.TOP];
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> POP >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
template <class Tpop>
void pop(Tpop &obj){
	if(obj.TOP < 0){
		pf << YELLOW_BB << "		Stack is Underflow!" << RESET << endl;
		return;
	}
	pf << RED_BB << "			 $" << RESET << obj.stk[obj.TOP--] << " Is Deleted!" << endl;
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PEEK >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
template <class Tpeek>
void peek(Tpeek &obj){
	if(obj.TOP < 0){
		pf << YELLOW_BB << "		Stack is Underflow!" << RESET << endl;
		return;
	}
	pf << RED_BB << "			 $" << RESET << obj.stk[obj.TOP] << endl;
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Display >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
template <class Tdisplay>
void display(Tdisplay &obj){
	if(obj.TOP < 0){
		pf << YELLOW_BB << "		Stack is Underflow!" << RESET << endl;
		return;
	}
	for(int i=obj.TOP; i>=0; i--)
		pf << RED_BB << "			 $" << RESET<< obj.stk[i] << endl;
}

int main(){

	stack<int> intobj;
	stack<char> charobj;
	stack<float> floatobj;
	stack<double> doubleobj;
	stack<string> strobj;
	
	int op, c = 0;
	while(1){
		pf << green_b << "		+++++++++++++++++++++++++++++++++" << endl;
		pf << "		+" << "   <<< STACK APPLICATION >>>" << "	+" << endl;
		pf << "		+++++++++++++++++++++++++++++++++" << endl;
		pf << "		+	" << "(1) INTEGER" << "		+" << endl;
		pf << "		+	" << "(2) CHARACTER" << "		+" << endl;
		pf << "		+	" << "(3) FLOAT" << "		+" << endl;
		pf << "		+	" << "(4) DOUBLE" << "		+" << endl;
		pf << "		+	" << "(5) STRING" << "		+" << endl;
		pf << "		+	" << "(0) EXIT" << "		+" << endl;
		pf << "		+++++++++++++++++++++++++++++++++" << RESET << endl;

		pf << blue_b << "	Enter Your Choice" << WHITE_BB << "$ " << RESET ;
		sf >> op;

		switch(op){
			case 1: pf << YELLOW_BB << "				Integer Stack Application Ready To Use!" << RESET << endl<< endl;
				if(intobj.TOP > -1){
					int op, c = 0;
					bool exitloop = false;
					while(!exitloop){
						pf << GREEN_B << "		+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
						pf << "		+	" << "(1) Continue With Exising Data" << "		+" << endl;
						pf << "		+	" << "(2) Create a new one" << "			+" << endl;
						pf << "		+	" << "(3) Back to main menu" << "			+" << endl;
						pf << "		+++++++++++++++++++++++++++++++++++++++++++++++++" << RESET << endl;
						pf << blue_b << "	Enter Your Choice" << WHITE_BB << "$ " << RESET ;
						sf >> op;	
						switch(op){
							case 1: opt(intobj);
								exitloop = true;
								break;

							case 2: intobj.TOP = -1;
								exitloop = true;
								opt(intobj);
								break;
				
							case 3: exitloop = true;
								break;

							default: pf << red_bb <<"	Invalid Input!" << RESET << endl;
								break;
						}				
					}	
				}else{				
					opt(intobj);
				}
				break;
				
			case 2: pf << YELLOW_BB <<"					Charater Stack Application Ready To Use!" << RESET << endl <<endl;
				if(charobj.TOP > -1){
					int op, c = 0;
					bool exitloop = false;
					while(!exitloop){
						pf << GREEN_B << "		+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
						pf << "		+	" << "(1) Continue With Exising Data" << "		+" << endl;
						pf << "		+	" << "(2) Create a new one" << "			+" << endl;
						pf << "		+	" << "(3) Back to main menu" << "			+" << endl;
						pf << "		+++++++++++++++++++++++++++++++++++++++++++++++++" << RESET << endl;
						pf << blue_b << "	Enter Your Choice" << WHITE_BB << "$ " << RESET ;
						sf >> op;	
						switch(op){
							case 1: opt(charobj);
								break;

							case 2: charobj.TOP = -1;
								opt(charobj);
								break;

							case 3: exitloop = true;
								break;

							default: pf << red_bb <<"	Invalid Input!" << RESET << endl;
								break;
						}				
					}	
				}else{
					opt(charobj);
				}				
				break;

			case 3: pf << YELLOW_BB <<"					Float Stack Application Ready To Use!" << RESET << endl << endl;
				if(floatobj.TOP > -1){
					int op, c = 0;
					bool exitloop = false;
					while(!exitloop){
						pf << GREEN_B << "		+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
						pf << "		+	" << "(1) Continue With Exising Data" << "		+" << endl;
						pf << "		+	" << "(2) Create a new one" << "			+" << endl;
						pf << "		+	" << "(3) Back to main menu" << "			+" << endl;						
						pf << "		+++++++++++++++++++++++++++++++++++++++++++++++++" << RESET << endl;
						pf << blue_b << "	Enter Your Choice" << WHITE_BB << "$ " << RESET ;
						sf >> op;	
						switch(op){
							case 1: opt(floatobj);
								break;

							case 2: floatobj.TOP = -1;
								opt(floatobj);
								break;

							case 3: exitloop = true;
								break;

							default: pf << red_bb <<"	Invalid Input!" << RESET << endl;
								break;
						}				
					}	
				}else{				
					opt(floatobj);
				}
				break;

			case 4: pf << YELLOW_BB <<"					Double Stack Application Ready To Use!" << RESET << endl << endl;
				if(doubleobj.TOP > -1){
					int op, c = 0;
					bool exitloop = false;
					while(!exitloop){
						pf << GREEN_B << "		+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
						pf << "		+	" << "(1) Continue With Exising Data" << "		+" << endl;
						pf << "		+	" << "(2) Create a new one" << "			+" << endl;
						pf << "		+	" << "(3) Back to main menu" << "			+" << endl;						
						pf << "		+++++++++++++++++++++++++++++++++++++++++++++++++" << RESET << endl;
						pf << blue_b << "	Enter Your Choice" << WHITE_BB << "$ " << RESET ;
						sf >> op;	
						switch(op){
							case 1: opt(doubleobj);
								break;

							case 2: intobj.TOP = -1;
								opt(doubleobj);
								break;

							case 3: exitloop = true;
								break;

							default: pf << red_bb <<"	Invalid Input!" << RESET << endl;
								break;
						}				
					}	
				}else{
					opt(doubleobj);
				}
				break;

			case 5: pf << YELLOW_BB <<"					Sting Stack Application Ready To Use!" << RESET << endl << endl;
				if(strobj.TOP > -1){
					int op, c = 0;
					bool exitloop = false;
					while(!exitloop){
						pf << GREEN_B << "		+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
						pf << "		+	" << "(1) Continue With Exising Data" << "		+" << endl;
						pf << "		+	" << "(2) Create a new one" << "			+" << endl;
						pf << "		+	" << "(3) Back to main menu" << "			+" << endl;						
						pf << "		+++++++++++++++++++++++++++++++++++++++++++++++++" << RESET << endl;
						pf << blue_b << "	Enter Your Choice" << WHITE_BB << "$ " << RESET ;
						sf >> op;	
						switch(op){
							case 1: opt(strobj);
								break;

							case 2: strobj.TOP = -1;
								opt(strobj);
								break;

							case 3: exitloop = true;
								break;

							default: pf << red_bb <<"	Invalid Input!" << RESET << endl;
								break;
						}				
					}	
				}else{				
					opt(strobj);
				}
				break;
		
			case 0: exit(0);

			default: 
				switch(++c){
					case 1: pf << red_bb <<"	Invalid Input!" << RESET << endl;
						pf << YELLOW_B <<"	Please read the option carefully..." << RESET << endl << endl;
						break;
					
					case 2: pf << red_bb <<"	Invalid Input!" << RESET << endl;
						pf << YELLOW_B <<"	Last chance please take care..." << RESET << endl << endl;
						break;
					case 3: pf << red_bb <<"	Invalid Input!" << RESET << endl;
						pf << YELLOW_B <<"	Thanks for using our application, Try again later." << RESET << endl << endl;
						exit(0);
					}
		}
	}
	
}
