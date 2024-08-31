#include "MASTER.h"

string decimalToHex(int deciml[])
{
	string hex="";
	int size = *(&deciml+1)-deciml;
	//int size=sizeof(deciml)/sizeof(deciml[0]);
	for(int i=0;i<size;i++)
	{
		if(deciml[i]>=0 && deciml[i]<=9)
			hex = hex + char('0' + deciml[i]);
		else if(deciml[i]>=10 && deciml[i]<=15)
			hex+=(char)('A'+(deciml[i]-10));
	}
	return hex;
}

string decimalToHexGen(int n){
	string ans = ""; 
    
    while (n != 0) { 
        // remainder variable to store remainder 
        int rem = 0; 
          
        // ch variable to store each character 
        char ch; 
        // storing remainder in rem variable. 
        rem = n % 16; 
  
        // check if temp < 10 
        if (rem < 10) { 
            ch = rem + 48; 
        } 
        else { 
            ch = rem + 55; 
        } 
          
        // updating the ans string with the character variable 
        ans += ch; 
        n = n / 16; 
    } 
      
    // reversing the ans string to get the final result 
    reverse(ans.begin(), ans.end());
    return ans;
}
