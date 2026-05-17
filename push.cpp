

template <class Tpush>
void push(Tpush &obj){
	  
	if(obj.TOP >= max){
		pf << YELLOW_BB << "		Stack Overflow!" << RESET << endl;
		return;
	}
	pf << BLUE_B "Enter the data" << WHITE_BB << "$ " << RESET;
	sf >> obj.stk[++obj.TOP];
}


