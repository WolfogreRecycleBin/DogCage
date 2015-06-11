#include "dogcage.hpp"
#include <iostream>
using namespace std;
int main()
{
	for(int i = 0; i <= 10000000; ++i)
	{
		int *p = new int(i);
		cout << i << endl;
	}
	
	return 0;
} 
