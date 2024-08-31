#include "MASTER.h"
#include "tools.h"

string CPE(string arg, string pc, string &sp, map<string,string> &memory, bool flag[]){

	if(validityAddress(arg)){

        string nextAddr = decimalToHexGen(hexToDecimalGen(pc)+3);

        if(flag[2] == true){
            string loc1 = decimalToHexGen(hexToDecimalGen(sp)-1);
            string loc2 = decimalToHexGen(hexToDecimalGen(sp)-2);

            if(loc1 < "0000" || loc1 > "FFFF"){
            cout<<"Error: "<<arg<<"\nAddress overflow\nThe program will quit\n";
            exit(0);
            }
            if(loc2 < "0000" || loc2 > "FFFF"){
            cout<<"Error: "<<arg<<"\nAddress overflow\nThe program will quit\n";
            exit(0);
            }

            sp = loc2;

            memory[loc1] = nextAddr.substr(0, 2);
            memory[loc2] = nextAddr.substr(2, 2);

            return arg;

        }
        else{
            return nextAddr;
        }


        
    }
	else{
		
		cout<<"Error encountered in: "<<arg<<"\n";
		cout<<"The program will quit\n";
		exit(0);
	}
}
