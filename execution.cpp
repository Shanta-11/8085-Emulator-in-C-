#include "MASTER.h"
#include "tools.h"
#include "arithmetic.h"
#include "load.h"
#include "logical.h"
#include "jump.h"

string nextAddress(string str,int n){

	int dec_val = hexToDecimalGen(str);
		
	dec_val+=n;
	return decimalToHexGen(dec_val);
}

string execution(string command, string Registers[], bool flag[], map<string,string>&memory,string programCounter, string &stackPointer){

	vector<string> commandPart;
	//string command = memory[programCounter];
	string inst;
	int commandSize;
	const char *partition = command.c_str();
	char *temporary = (char*)partition;
	const char *delimiter = " ,";
	char *part = strtok(temporary,delimiter);

	while(part!=NULL){

		inst = part;
		commandPart.push_back(inst);
		part = strtok(NULL,delimiter);

	}

	if(commandPart[0] == "MOV"){

			MOV(commandPart[1],commandPart[2],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "MVI"){

			MVI(commandPart[1],commandPart[2],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "LXI"){

			LXI(commandPart[1],commandPart[2],Registers,flag,memory, stackPointer);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "LDA"){

			LDA(commandPart[1],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "STA"){

			STA(commandPart[1],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "LHLD"){

			LHLD(commandPart[1],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "SHLD"){

			SHLD(commandPart[1],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "STAX"){

			STAX(commandPart[1],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "XCHG"){

			XCHG(Registers,flag);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "ADD"){

			ADD(commandPart[1],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "ADI"){

			ADI(commandPart[1],Registers,flag);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "SUB"){

			SUB(commandPart[1],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "SUI"){

			SUI(commandPart[1],Registers,flag);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "INR"){

			INR(commandPart[1],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "DCR"){

			DCR(commandPart[1],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "INX"){

			INX(commandPart[1],Registers,flag);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "DCX"){

			DCX(commandPart[1],Registers,flag);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "DAD"){

			DAD(commandPart[1],Registers,flag);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "CMA"){

			CMA(Registers,flag);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "CMP"){

			CMP(commandPart[1],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "JMP"){

			return JMP(commandPart[1],Registers,flag);
	}
	else if(commandPart[0] == "JC"){

			return JC(commandPart[1],programCounter,Registers,flag);
	}
	else if(commandPart[0] == "JNC"){

			return JNC(commandPart[1],programCounter,Registers,flag);
	}
	else if(commandPart[0] == "JZ"){

			return JZ(commandPart[1],programCounter,Registers,flag);
	}
	else if(commandPart[0] == "JNZ"){

			return JNZ(commandPart[1],programCounter,Registers,flag);
	}
	else if(commandPart[0] == "SET"){

			SET(commandPart[1],commandPart[2],memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "ANA"){
			ANA(commandPart[1],Registers,flag, memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "ANI"){
			ANI(commandPart[1],Registers,flag, memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "ORA"){
			ORA(commandPart[1],Registers,flag, memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "ORI"){
			ORI(commandPart[1],Registers,flag, memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "XRA"){
			XRA(commandPart[1],Registers,flag, memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "XRI"){
			XRI(commandPart[1],Registers,flag, memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "CMC"){
			CMC(flag);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "STC"){
			STC(flag);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "CPI"){

			CPI(commandPart[1],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "JP"){

			return JP(commandPart[1],programCounter,Registers,flag);
	}
	else if(commandPart[0] == "JM"){

			return JM(commandPart[1],programCounter,Registers,flag);
	}
	else if(commandPart[0] == "JPE"){

			return JPE(commandPart[1],programCounter,Registers,flag);
	}
	else if(commandPart[0] == "JPO"){

			return JPO(commandPart[1],programCounter,Registers,flag);
	}
	else if(commandPart[0] == "PUSH"){

			PUSH(commandPart[1],Registers, stackPointer, memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "POP"){

			POP(commandPart[1],Registers, stackPointer, memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "CALL"){

			return CALL(commandPart[1],programCounter , stackPointer, memory);
	}
	else if(commandPart[0] == "RET"){

			return RET(stackPointer, memory);
	}
	else if(commandPart[0] == "CC"){

			return CC(commandPart[1],programCounter , stackPointer, memory, flag);
	}
	else if(commandPart[0] == "CNC"){

			return CNC(commandPart[1],programCounter , stackPointer, memory, flag);
	}
	else if(commandPart[0] == "CZ"){

			return CZ(commandPart[1],programCounter , stackPointer, memory, flag);
	}
	else if(commandPart[0] == "CNZ"){

			return CNZ(commandPart[1],programCounter , stackPointer, memory, flag);
	}
	else if(commandPart[0] == "CP"){

			return CP(commandPart[1],programCounter , stackPointer, memory, flag);
	}
	else if(commandPart[0] == "CM"){

			return CM(commandPart[1],programCounter , stackPointer, memory, flag);
	}
	else if(commandPart[0] == "CPE"){

			return CPE(commandPart[1],programCounter , stackPointer, memory, flag);
	}
	else if(commandPart[0] == "CPO"){

			return CPO(commandPart[1],programCounter , stackPointer, memory, flag);
	}

	else if(commandPart[0] == "RC"){

			return RC(stackPointer, memory, flag, programCounter);
	}
	else if(commandPart[0] == "RNC"){

			return RNC(stackPointer, memory, flag, programCounter);
	}
	else if(commandPart[0] == "RZ"){

			return RZ(stackPointer, memory, flag, programCounter);
	}
	else if(commandPart[0] == "RNZ"){

			return RNZ(stackPointer, memory, flag, programCounter);
	}
	else if(commandPart[0] == "RP"){

			return RP(stackPointer, memory, flag, programCounter);
	}
	else if(commandPart[0] == "RM"){

			return RM(stackPointer, memory, flag, programCounter);
	}
	else if(commandPart[0] == "RPE"){

			return RPE(stackPointer, memory, flag, programCounter);
	}
	else if(commandPart[0] == "RPO"){

			return RPO(stackPointer, memory, flag, programCounter);
	}
	
	return "";
}
