#include "header/MASTER.h"
#include "header/tools.h"

void XRA(string arg, string registers[],bool flag[],map<string,string> &memory){

	int length = arg.length();
	if(length == 1){
	
		if(arg == "M"){
			string address=registers[5]+registers[6];
            string data = memory[address];

            flag[0]=false;

            int A_val = hexToDecimalGen(registers[0]);
            int M_val = hexToDecimalGen(data);

            bitset<8> A_bin(A_val);
            bitset<8> M_bin(M_val);
            bitset<8> variable;

            for(int i=0;i<8;i++){
                if(A_bin.test(i) != M_bin.test(i)){
                    variable.set(i);
                }
            }

            int parity = variable.count();
            if(parity%2 == 0 && parity!=0)
                flag[2] = true;
            else
                flag[2] = false;
            /*Setting sign flag*/
            flag[7] = variable[7];
            /*Setting zero flag*/
            if(parity == 0)
                flag[6] = true;
            
            registers[0] = decimalToHexGen(variable.to_ulong());

		}
        else if(isValidRegister(arg)){
            string data = registers[registerNumber(arg)];

            flag[0]=false;

            int A_val = hexToDecimalGen(registers[0]);
            int M_val = hexToDecimalGen(data);

            bitset<8> A_bin(A_val);
            bitset<8> M_bin(M_val);
            bitset<8> variable;

            for(int i=0;i<8;i++){
                if(A_bin.test(i) != M_bin.test(i)){
                    variable.set(i);
                }
            }

            int parity = variable.count();
            if(parity%2 == 0 && parity!=0)
                flag[2] = true;
            else
                flag[2] = false;
            /*Setting sign flag*/
            flag[7] = variable[7];
            /*Setting zero flag*/
            if(parity == 0)
                flag[6] = true;
            
            registers[0] = decimalToHexGen(variable.to_ulong());
        }
		else{
			
			cout<<"Error: "<<arg<<"\nInvalid data content\nThe program will quit\n";
			exit(0);
			/*Error message of invalid data content*/
		}
	}
	else{
		
		cout<<"Error: "<<arg<<"\nInvalid data size\nThe program will quit\n";
		exit(0);
		/*Error message of invalid data size*/
	}
	
}

