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
#include <math.h>

using namespace std;
//1,2,3,4...10...99..999
int getKthBit(int n)
{
	int i=1,j=0,mul=1;
	while(true)
	{
		if(j+i*9*mul>=n)break;
		j+=i*9*mul;
		i++;
		mul*=10;
	}
	int t=mul+(n-j-1)/i;
	stringstream ss;
	ss<<t;
	return ss.str()[(n-j-1)%i]-'0';
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<getKthBit(4)<<endl;
	cout<<getKthBit(9)<<endl;
	cout<<getKthBit(10)<<endl;
	cout<<getKthBit(11)<<endl;
	cout<<getKthBit(188)<<endl;
	cout<<getKthBit(189)<<endl;
	cout<<getKthBit(190)<<endl;
	cout<<getKthBit(191)<<endl;
	cout<<getKthBit(192)<<endl;
	cout<<getKthBit(193)<<endl;
	cout<<getKthBit(194)<<endl;
	cout<<getKthBit(195)<<endl;
	return 0;
}


