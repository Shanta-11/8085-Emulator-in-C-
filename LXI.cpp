#include "MASTER.h"
#include "tools.h"
void LXI (string arg1,string arg2,string registers[],bool flags[],map<string,string> &memory, string &sp)
{
	int l1=arg1.length();
	int l2=arg2.length();
	if((l1==1 || l1 == 2)&&l2==4)
	{
		if(arg1=="M")
		{
			if(validityAddress(arg2))
			{
				registers[5]=arg2.substr(0, 2);
				registers[6]=arg2.substr(2, 2);
			}
			else
			{
				cout<<"Error: "<<arg1<<" & "<<arg2<<"\nInvalid content\nThe program will quit\n";
				exit(0);
			}
		}
		if(arg1=="SP")
		{
			if(validityAddress(arg2))
			{
				sp = arg2;
			}
			else
			{
				cout<<"Error: "<<arg1<<" & "<<arg2<<"\nInvalid content\nThe program will quit\n";
				exit(0);
			}
		}
		else
		{
			if(validityRegisterPair(arg1)&&validityAddress(arg2))
			{
				
				registers[registerNumber(arg1)]=arg2.substr(0, 2);
				registers[registerNumber(arg1)+1]=arg2.substr(2, 2);
			}
			else
			{
				cout<<"Error: "<<arg1<<" & "<<arg2<<"\nInvalid content\nThe program will quit\n";
				exit(0);
			}
		}
	}
	else
	{
		cout<<"Error: "<<arg1<<" & "<<arg2<<"\nInvalid arguments\nThe program will quit\n";
				exit(0);
		}
}
