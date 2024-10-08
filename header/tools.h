#ifndef _TOOLS_H
#define _TOOLS_H

bool validityAddress(string);
string hexAdd(string,string,bool[],bool);
string hexSub(string,string,bool[],bool);
string hexAdd16bit(string,string,bool[],bool);
string hexSub16bit(string,string,bool[],bool);
void hexToDecimal(string,int[]);
bool isValidRegister(string);
bool validityRegisterPair(string);
bool validityData(string);
bool isValidHexCmd(string);
int registerNumber(string);
bool isValidCommand(string);
string increaseAddress(string);
string complement(string);
string decimalToHex(int[]);
int operationSize(string);
string execution(string, string[], bool[], map<string,string>&,string, string&);
string updatedAddress(string,map<string,string>&);
int hexToDecimalGen(string);
string decimalToHexGen(int);

#endif
