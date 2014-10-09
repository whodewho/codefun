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

using namespace std;

void printSpiralMatrix(int n)
{
	if(!n)return;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int t=min(min(n-1-i,i), min(n-1-j,j));
			int sum=0;
			for(int k=0;k<t;k++)
				sum+=((n-k*2)*4-4);
			if(i==t)
			{
				sum+=(j-t+1);
			}
			else if(i==n-t-1)
			{
				sum+=((n-t-1-t)*2+(n-t-1-j+1));
			}
			else if(j==n-t-1)
			{
				sum+=(n-t-1-t+1)+i-t;
			}
			else
			{
				sum+=((n-t-1-t)*3+(n-t-1-i+1));
			}
			cout<<setw(2)<<(n*n-sum+1)<<" ";
			if(j==n-1)cout<<endl;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	printSpiralMatrix(5);
	printSpiralMatrix(1);
	printSpiralMatrix(4);
	printSpiralMatrix(9);
	return 0;
}



