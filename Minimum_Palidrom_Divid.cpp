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

vector<vector<bool> > getPalidromMatrix(string s)
{
	int n=s.size();
	vector<vector<bool> > matrix(n, vector<bool>(n, false));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(i==j)matrix[j][i]=true;
			else if(j+1==i)matrix[j][i]=s[i]==s[j];
			else matrix[j][i]=s[i]==s[j]&&matrix[j+1][i-1];
		}
	}
	return matrix;
}

vector<string> dividString(vector<pair<int, int> > &divid, string s)
{
	int n=s.size();
	int j=n-1;
	vector<string> result;
	while(j>=0)
	{
		int prev=divid[j].second;
		result.push_back(s.substr(prev, j-prev+1));
		j=prev-1;
	}
	reverse(result.begin(), result.end());
	return result;
}

vector<string> minmalPalidrom(string s)
{
	vector<vector<bool> > palidromMatrix=getPalidromMatrix(s);
	int n=s.size();
	vector<pair<int, int> > divid(n, pair<int, int>(INT_MAX, 0));
	for(int i=0;i<n;i++)
	{
		if(palidromMatrix[0][i])
		{
			divid[0].first=0;
			divid[0].second=0;
		}
		else
		{
			for(int k=0;k<i;k++)
			{
				if(palidromMatrix[k+1][i])
				{
					if(divid[k].first+1<divid[i].first)
					{
						divid[i].first=divid[k].first+1;
						divid[i].second=k+1;
					}
				}
			}
		}
	}

	return dividString(divid, s);
}



int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> result=minmalPalidrom("aabaa");
	for(int i=0;i<result.size();i++)
		cout<<result[i]<<endl;
	return 0;
}
