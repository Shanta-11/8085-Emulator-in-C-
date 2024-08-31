#include "header/MASTER.h"
#include "header/tools.h"
bool alien(string str){
	
	int l = str.length();
	for(int i=0;i<l;i++){
		
		if(((str[i]>='0' && str[i]<='9') || str[i] == ' ' || str[i] == ',' || (str[i]>='A' && str[i]<='Z')))
			continue;
		else{
			cout<<"Error: Invalid Characters found"<<endl;
			return false;
		}
			
	}
	return true;
}

bool argumentValidation(vector<string> &memory ,string str){
	
	string zero[] = {"HLT","CMA","XCHG", "CMC", "STC", "RET", "RC", "RNC", "RZ", "RNZ", "RP", "RM", "RPE", "RPO"};
	string one[] = {"CMP","JMP","JC","JNC","JZ","JNZ","JP","JM","JPE", "JPO","ADD","ADI","SUB","SUI","INR","INX","DCR","DCX","DAD","LDA","STA","SHLD","LHLD","STAX","MOVE", "ANA", "ANI", "ORA", "ORI", "XRA", "XRI", "CPI", "PUSH", "POP", "CALL", "CC", "CNC", "CZ", "CNZ", "CP", "CM", "CPE", "CPO"};
	string two[] = {"SET","MOV","MVI","LXI"};
	int length = sizeof(zero)/sizeof(zero[0]);
	for(int i=0;i<length;i++){
		
		if(str == zero[i] && memory.size()==1)
			return true;
	}
	length = sizeof(one)/sizeof(one[0]);
	for(int i=0;i<length;i++){
		
		if(str == one[i] && memory.size()==2)
			return true;
	}
	length = sizeof(two)/sizeof(two[0]);
	for(int i=0;i<length;i++){
		
		if(str == two[i] && memory.size()==3)
			return true;
	}
	cout<<"ERROR: Invalid number of arguments"<<endl;
	return false;
}

bool isValidInstruction(string str){
	
	string repository[] = {"HLT","MOV","STAX","XCHG","ADD","SUB","INR","DCR","INX","DCX","DAD","CMA","CMP","MVI","ADI","SUI","SET","LXI","LDA","STA","SHLD","LHLD","JMP","JC","JNZ","JNC","JZ", "CMC", "STC", "RET", "ANA", "ANI", "ORA", "ORI", "XRA", "XRI", "CPI", "PUSH", "POP", "CALL","JP","JM","JPE", "JPO", "CC", "CNC", "CZ", "CNZ", "CP", "CM", "CPE", "CPO", "RC", "RNC", "RZ", "RNZ", "RP", "RM", "RPE", "RPO" };
	int l = sizeof(repository)/sizeof(repository[0]);
	bool flag = false;
	for(int i = 0;i<l;i++){
		
		if(str == repository[i]){
			flag = true;
			break;
		}
	}
	if(!flag)
		cout<<"ERROR: Invalid Instruction"<<endl;
	return flag;
}

bool isValidCommand(string command){

	string copy = command;
	vector <string> tokens;
	bool flag = false;
	const char *ch = command.c_str();
	char *var = (char*)ch;
	const char *delimiter = " ,";
	char *pch = strtok (var,delimiter);
	while(pch != NULL){
		
		tokens.push_back(pch);
		pch = strtok(NULL,delimiter);
	}
	if(isValidInstruction(tokens[0]) && argumentValidation(tokens,tokens[0]) && alien(copy))
	{
		flag = true;
		if(tokens.size()>1){
		
			for(int i = 1;i<tokens.size();i++){
			
				string temp = tokens[i];
				int tempLength = tokens[i].length();
				switch(tempLength){
				
					case 1:
						if(temp == "M")
							flag = true;
						else
							flag = isValidRegister(temp);
						break;
					case 2:
						flag = (temp == "SP") || isValidHexCmd(temp);
						break;
					case 4:
						flag = isValidHexCmd(temp);
						break;
					default:
						flag = false;
						break;
				}
				if(!flag){
					break;
				}
					
			}
		}
		return flag;
	}
	return flag;
}