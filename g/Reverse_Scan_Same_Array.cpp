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



vector<vector<int> > getOddVec()
{
	vector<vector<int> > result;
	result.push_back(vector<int>(1,0));
	result.push_back(vector<int>(1,1));
	result.push_back(vector<int>(1,8));
	return result;
}

vector<vector<int> > getEvenVec()
{
	vector<vector<int> > result;
	result.push_back(vector<int>(2,0));
	result.push_back(vector<int>(2,1));
	result.push_back(vector<int>(2,8));
	vector<int> tmp;
	tmp.push_back(6);
	tmp.push_back(9);
	result.push_back(tmp);
	reverse(tmp.begin(), tmp.end());
	result.push_back(tmp);
	return result;
}

vector<vector<int> > mulTwoVec(vector<vector<int> > first, vector<vector<int> > second)
{
	vector<vector<int> > result;
	for(int i=0;i<first.size();i++)
		for(int j=0;j<second.size();j++)
		{
			vector<int> tmp(first[i].begin(), first[i].end());
			if(second[j].size()==1)
			{
				tmp.insert(tmp.begin()+tmp.size()/2, second[j][0]);
			}
			else
			{
				tmp.insert(tmp.begin(), second[j][0]);
				tmp.push_back(second[j][1]);
			}
			result.push_back(tmp);
		}
		return result;
}

vector<vector<vector<int> > > reverseScanSameResultArray(int n)
{
	vector<vector<vector<int> > > result;
	vector<vector<int> > odd = getOddVec();
	vector<vector<int> > even = getEvenVec();
	for(int i=1;i<=n;i++)
	{
		if(i==1)result.push_back(odd);
		else if(i==2)result.push_back(even);
		else if(i%2==0)result.push_back(mulTwoVec(result[result.size()-2], odd));
		else result.push_back(mulTwoVec(result[result.size()-2], even));
	}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
    vector<vector<vector<int> > > result=reverseScanSameResultArray(5);
	for(int i=0;i<result.size();i++)
	{
		for(int j=0;j<result[i].size();j++)
		{
			for(int k=0;k<result[i][j].size();k++)
				cout<<result[i][j][k]<<" ";
			cout<<endl;
		}
		cout<<endl;
		cout<<i<<"----"<<endl;
	}
	return 0;
}
