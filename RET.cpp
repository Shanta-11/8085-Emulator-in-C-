#include "MASTER.h"
#include "tools.h"

string RET(string &sp, map<string,string> &memory){
    string loc1 = decimalToHexGen(hexToDecimalGen(sp)+1);
    string loc2 = decimalToHexGen(hexToDecimalGen(sp)+2);

    if(loc1 < "0000" || loc1 > "FFFF"){
        cout<<"Error: "<<"RET"<<"\nAddress overflow\nThe program will quit\n";
        exit(0);
    }
    if(loc2 < "0000" || loc2 > "FFFF"){
        cout<<"Error: "<<"RET"<<"\nAddress overflow\nThe program will quit\n";
        exit(0);
    }
    
    string return_value = memory[loc1] + memory[sp];
    
    sp = loc2;
    return return_value;
}
