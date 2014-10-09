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

using namespace std;

void shuffle(vector<int> &num, int &k)
{
	int i=0, n=num.size();
	while(i<n)
	{
		if(i==k||num[i]==num[num[i]]||num[i]==i)
		{
			i++;
			continue;
		}
		num[k]=num[num[i]];
		num[num[i]]=num[i];
		int j=i;
		i=min(i,k);
		k=j;
	}
}

void testShuffle()
{
	int n=20, k=6;
	vector<int> num;
	for(int i=0;i<n;i++)
		num.push_back(i);
	random_shuffle(num.begin(), num.end());
	for(int i=0;i<n;i++)
	{
		if(i==k)cout<<"->";
		cout<<num[i]<<" ";
	}
	cout<<endl;
	shuffle(num, k);
	for(int i=0;i<n;i++)	
	{
		if(i==k)cout<<"->";
		cout<<num[i]<<" ";
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	testShuffle();
	return 0;
}



