#include "stdafx.h"
#include "iostream"
#include "vector"
#include "string"
#include "map"
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <stack>

using namespace std;

struct Node{
	int val;
	Node *left;
	Node *right;
	Node(int _v):val(_v),left(NULL),right(NULL){}
};

float stringToFloat(string s)
{
	float result=0;
	int n=s.size();
	if(!n)return result;
	int sign=1, i=0;
	if(s[i]=='-'||s[i]=='+')
	{
		if(s[i]=='-')sign=-1;
		i++;
	}
	for(;i<n;i++)
	{
		if(s[i]=='.'){i++;break;}
		result=result*10+s[i]-'0';
	}

	float divisor=10.0;
	for(;i<n;i++)
	{
		result=result+(s[i]-'0')/divisor;
		divisor*=10;
	}
	return sign*result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<stringToFloat("-874.234")<<endl;
	cout<<stringToFloat("+0.234")<<endl;
	cout<<stringToFloat("234")<<endl;
	return 0;
}



