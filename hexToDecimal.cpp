#include "MASTER.h"
#include <string>

void hexToDecimal(string pc,int arr[]){
 
	int l = pc.length();
	int p = 0;
	for(int i =0 ;i<l;i++){
	
		if(pc[i]>='0' && pc[i]<='9')
			arr[i] = pc[i] - '0';
		else 
			arr[i] = 10 + (pc[i] - 'A'); 
	}
}

int hexToDecimalGen(string hexVal){
	int len = hexVal.size(); 
  
    // Initializing base value to 1, i.e 16^0 
    int base = 1; 
  
    int dec_val = 0; 
  
    // Extracting characters as digits from last 
    // character 
    for (int i = len - 1; i >= 0; i--) { 
        // if character lies in '0'-'9', converting 
        // it to integral 0-9 by subtracting 48 from 
        // ASCII value 
        if (hexVal[i] >= '0' && hexVal[i] <= '9') { 
            dec_val += (int(hexVal[i]) - 48) * base; 
  
            // incrementing base by power 
            base = base * 16; 
        } 
  
        // if character lies in 'A'-'F' , converting 
        // it to integral 10 - 15 by subtracting 55 
        // from ASCII value 
        else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') { 
            dec_val += (int(hexVal[i]) - 55) * base; 
  
            // incrementing base by power 
            base = base * 16; 
        } 
    } 
    return dec_val;
}
