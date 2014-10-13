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

string toPoint(int divid, int divisor)
{
	if(divisor==0)return "";
	if(divid==0)return "0";

	int intPart=divid/divisor;
	divid=divid%divisor;
	map<int, int> rest;
	vector<int> result;
	int start=-1, index=0;
	while(divid!=0)
	{
		map<int, int>::iterator it=rest.find(divid);
		if(it!=rest.end())
		{
			start=it->second;
			break;
		}
		else
		{
			rest[divid]=index;
		}

		divid*=10;
		if(divid>=divisor)
		{
			result.push_back(divid/divisor);
			divid%=divisor;
		}
		else
		{
			result.push_back(0);
		}
		index++;
	}

	string s="";
	for(int i=0;i<result.size();i++)
	{
		if(i==start)
		{
			s+="(";
		}
		s.push_back(result[i]+'0');
	}
	if(start!=-1)
	{
		s.push_back(')');
	}

	if(intPart)
	{
		stringstream ss;
		ss<<intPart;
		s=ss.str()+"."+s;
	}
	else
	{
		s="0."+s;
	}
	return s;
}


int _tmain(int argc, _TCHAR* argv[])
{
	cout<<toPoint(112,11)<<endl;
	return 0;
}


