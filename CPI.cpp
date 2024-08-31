#include "MASTER.h"
#include "tools.h"
void CPI (string arg1,string registers[],bool flag[],map<string,string> &memory)
{
	int l1=arg1.length();
	if(l1==2)
	{
		if(validityData(arg1))
		{
		    
			if(registers[0]<arg1)
			{
			    flag[0]=true;
			}
			else if(registers[0]==arg1)
			{
				flag[6]=true;
				//cout<<"zero set\n";
			}
			else
			{
				//cout<<"both reset\n";
				flag[0]=false;
				flag[6]=false;
			}
		}
		else{
			
			cout<<"Error: "<<arg1<<"\nInvalid registers\nThe program will quit\n";
			exit(0);
		}
	}
	else{
		
		cout<<"Error: "<<arg1<<"\nInvalid argument\nThe program will quit\n";
		exit(0);
	}
}
