#include "stdafx.h"
#include "iostream"
#include "vector"
#include "string"
#include "map"
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <stack>
#include <sstream>
#include <iomanip>
#include <random>       
#include <assert.h>
#include <iterator>
#include <queue>

using namespace std;


int getKthArgly(int k)
{
	int two=2, three=3, five=5, number;
	for(int i=0;i<k-1;i++)
	{
		if(two<three&&two<five)
		{
			two=2*(two/2+1);
		}
		else if(three<two&&three<five)
		{
			three=3*(three/3+1);
		}
		else if(five<two&&five<three)
		{
			five=5*(five/5+1);
		}
	}
	number=min(two, min(three, five));
	return number;
}


int _tmain(int argc, _TCHAR* argv[])
{
	cout<<getKthArgly(5)<<endl;
	return 0;
}


