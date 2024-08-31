#include "MASTER.h"
#include "tools.h"

void PUSH(string arg, string registers[], string &sp, map<string,string> &memory){

    if(arg.length() == 1){
        if(validityRegisterPair(arg)){

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

            memory[loc1] = registers[registerNumber(arg)];
            memory[loc2] = registers[registerNumber(arg)+1];

        }
        else{
		
            cout<<"Error: "<<arg<<"\nInvalid arguments\nThe program will quit\n";
            exit(0);
            /*Error message of invalid arguments*/
        }

    }
    else{
		
		cout<<"Error: "<<arg<<"\nInvalid arguments\nThe program will quit\n";
		exit(0);
		/*Error message of invalid arguments*/
	}

}