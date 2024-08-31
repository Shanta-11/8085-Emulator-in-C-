#include "MASTER.h"
/* This function takes in a complete command as an input and breaks it in 
	operand and opcode and checks the size of the command */
	
int operationSize(string str){

	string one[] = {"HLT","MOV","STAX","XCHG","ADD","SUB","INR","DCR","INX","DCX","DAD","CMA","CMP", "ANA", "ORA", "XRA", "CMC", "STC", "PUSH", "POP", "RET", "RC", "RNC", "RZ", "RNZ", "RP", "RM", "RPE", "RPO"};
	string two[] = {"MVI","ADI","SUI", "ANI", "ORI", "XRI", "CPI"};
	string three[] = {"LXI","LDA","STA","SHLD","LHLD","JMP","JC","JNZ","JNC","JZ","JP","JM","JPE", "JPO","SET", "CALL", "CC", "CNC", "CZ", "CNZ", "CP", "CM", "CPE", "CPO"};
	const char *ch = str.c_str();
	char *var = (char*)ch;
	const char *delimiter = " ,";
	char *pch = strtok (var,delimiter);
	string query = pch;
	
	int length = sizeof(one)/sizeof(one[0]);
	for(int i=0;i<length;i++){
		
		if(one[i] == query)
			return 1;
	}
	length = sizeof(two)/sizeof(two[0]);
	for(int i=0;i<length;i++){
		
		if(two[i] == query)
			return 2;
	}
	length = sizeof(three)/sizeof(three[0]);
	for(int i=0;i<length;i++){
		
		if(three[i] == query)
			return 3;
	}
	return 0;
}
