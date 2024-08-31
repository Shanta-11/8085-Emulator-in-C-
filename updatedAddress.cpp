#include "MASTER.h"
#include "tools.h"

string updatedAddress(string PC,map<string,string>&Memory){ 
	
	string command = Memory[PC];
	string opcode;
	if(command == "HLT" || command == "XCHG" || command == "CMA"){
		
		opcode = command;
	}
	else{
		
		const char *partition = command.c_str();
		char *temporary = (char*)partition;
		const char *delimiter = " ,";
		char *part = strtok(temporary,delimiter);
		opcode = part;
	}
	int n = operationSize(opcode);
	string result;
	
	
	int dec_val = hexToDecimalGen(PC);
	
	dec_val+=n;
	result = decimalToHexGen(dec_val);
	
	return result;
}
