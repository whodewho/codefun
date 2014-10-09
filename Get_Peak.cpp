
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

using namespace std;

int getPeak(int A[], int n)
{
	if(!n)return -1;
	if(n==1)return A[0];
	int l=0,h=n-1;
	while(l<=h)
	{
		if(l==h)
		{
			return A[l];
		}
		else if(l+1==h)
		{
			return max(A[l], A[h]);
		}
		else
		{
			int m=(l+h)/2;
			if(A[l]<=A[m])l=m;
			else h=m;
		}
	}
	return -1;
}

void testGetPeak()
{
	int A[100];
	int k=34, n=57;
	for(int i=0;i<n;i++)
	{
		if(i<k)A[i]=i;
		else A[i]=n-i;
	}
	A[k]=k;
	A[k+1]=34;
	cout<<getPeak(A, 57)<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	testGetPeak();
	return 0;
}


