#include "cppTimeStamp.h"


void trashFunc()
{
	int counter = 0;
	for (int i = 0; i <= 10000000; i++) counter++;
}


int main()
{
	auto stamp = CPPTIMESTAMP(trashFunc);
	stamp();
	return 0;
}

//23:43:13 Jul 17 2025
//Working time of function : trashFunc is 0.00536090 sec.