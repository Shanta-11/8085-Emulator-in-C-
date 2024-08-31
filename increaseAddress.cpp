#include "header/MASTER.h"
#include "header/tools.h"

string increaseAddress(string a)
{
	int dec = hexToDecimalGen(a);
	dec++;
	return decimalToHexGen(dec);
}
