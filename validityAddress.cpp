#include "header/MASTER.h"
#include <string>
using namespace std;

bool validityAddress(string data)
{
	bool flag;
	int l=data.length();
	for(int i=0;i<l;i++){
		if(( data[i]>='0' && data[i]<='9')||( data[i]>='A' && data[i]<='F' ))
			flag = true;
		else{		
			flag = false;
			break;
		}
	}
	return flag;
}

bool isValidRegister(string reg)
{
	if(reg=="A"||reg=="B"||reg=="C"||reg=="D"||reg=="E"||reg=="H"||reg=="L")
		return true;
	else
		return false;
}

bool validityRegisterPair(string reg)
{
	if(reg=="B"||reg=="D"||reg=="H"||reg=="M")
		return true;
	else 
		return false;
}

bool checkHex(string data){

	int l = data.length();

	for(int i=0;i<l;i++){
		if(((data[i]>='0' && data[i]<='9')||(data[i]>='A' && data[i]<='F')))
			continue;
		else
			return false;
	}
	return true;
}

bool isValidHexCmd(string data){
	bool flag;
	int l = data.length();
	if((l == 2 || l == 4) && checkHex(data))
		return true;
	return false;
}

bool isHexadecimal(char a){

	if((a>='0' && a<='9') || (a>='A' && a<='F'))
		return true;
	else
		return false;
}

bool validityData(string a){

	int l=a.length();
	if(l==2 && isHexadecimal(a[0]) && isHexadecimal(a[1]))
		return true;
	else 
		return false;
}
