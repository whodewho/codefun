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
#include <vector>
#include <set>

using namespace std;

bool startsWith(string s, string p)
{
	int i=0,j=0;
	while(i<s.size()&&j<p.size())
	{
		if(s[i]!=p[j])break;
		i++;
		j++;
	}
	if(j==p.size())return true;
	return false;
}

pair<int, int> largestCommonPrefixRange(vector<string> strs, string s)
{
	pair<int, int> result(-1,-2);
	pair<int, int> range(-1,-2);
	for(int i=0;i<strs.size();i++)
	{
		if(startsWith(strs[i],s))
		{
			if(range.first==-1)range.first=i;
			range.second=i;
		}
		else
		{
			if(range.second-range.first>result.second-result.first)
			{
				result.first=range.first;
				result.second=range.second;
			}
			range.first=-1;
			range.second=-2;
		}
	}

	if(range.second-range.first>result.second-result.first)
	{
		result.first=range.first;
		result.second=range.second;
	}
	return result;
}

void testNormalLargestCommonPrefixRange()
{
	vector<string> tmp;
	tmp.push_back("abd");
	tmp.push_back("abc");
	tmp.push_back("abd");
	tmp.push_back("aef");
	tmp.push_back("abd");
	tmp.push_back("abc");
	tmp.push_back("abd");
	tmp.push_back("abd");
	pair<int, int> res=largestCommonPrefixRange(tmp, "ab");
	assert(res.first==4&&res.second==7);
}

void testNoneLargestCommonPrefixRange()
{
	vector<string> tmp;
	tmp.push_back("ad");
	tmp.push_back("ac");
	pair<int, int> res=largestCommonPrefixRange(tmp, "ab");
	assert(res.first==-1&&res.second==-2);
}

void testEmptyLargestCommonPrefixRange()
{
	vector<string> tmp;
	pair<int, int> res=largestCommonPrefixRange(tmp, "ab");
	assert(res.first==-1&&res.second==-2);
}


int _tmain(int argc, _TCHAR* argv[])
{
	testNormalLargestCommonPrefixRange();
	testNoneLargestCommonPrefixRange();
	testEmptyLargestCommonPrefixRange();
	return 0;
}
