#ifndef _JUMP_H
#define _JUMP_H

string JMP(string, string[], bool[]);
/*All other jump statements require program counter to be passed as an 
	argument as to find the next possible location possible*/
/*Second argument is the address in program counter*/

string JC(string, string, string[],bool[]);
string JNC(string, string, string[],bool[]);
string JZ(string, string, string[],bool[]);
string JNZ(string, string, string[],bool[]);
string JP(string, string, string[],bool[]);
string JM(string, string, string[],bool[]);
string JPE(string, string, string[],bool[]);
string JPO(string, string, string[],bool[]);

void PUSH(string, string[], string&, map<string,string>&);
void POP(string, string[], string&, map<string,string>&);

string CALL(string, string, string&, map<string,string>&);

string CC(string, string, string&, map<string,string>&, bool[]);
string CNC(string, string, string&, map<string,string>&, bool[]);
string CZ(string, string, string&, map<string,string>&, bool[]);
string CNZ(string, string, string&, map<string,string>&, bool[]);
string CP(string, string, string&, map<string,string>&, bool[]);
string CM(string, string, string&, map<string,string>&, bool[]);
string CPE(string, string, string&, map<string,string>&, bool[]);
string CPO(string, string, string&, map<string,string>&, bool[]);

string RET(string&, map<string,string>&);

string RC(string&, map<string,string>&, bool[], string);
string RNC(string&, map<string,string>&, bool[], string);
string RZ(string&, map<string,string>&, bool[], string);
string RNZ(string&, map<string,string>&, bool[], string);
string RP(string&, map<string,string>&, bool[], string);
string RM(string&, map<string,string>&, bool[], string);
string RPE(string&, map<string,string>&, bool[], string);
string RPO(string&, map<string,string>&, bool[], string);


#endif
