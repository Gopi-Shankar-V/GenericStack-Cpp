#ifndef HEADER_H
#define HEADER_H

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

template <class Topt>
extern void opt1(Topt &);

template <class Tpush>
void push(Tpush &obj){
	  
	if(obj.TOP >= max){
		pf << YELLOW_BB << "		Stack Overflow!" << RESET << endl;
		return;
	}
	pf << BLUE_B "Enter the data" << WHITE_BB << "$ " << RESET;
	sf >> obj.stk[++obj.TOP];
}
#endif
