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


bool matchHelper(string s, string p)
{
	int i=0, j=0, m=s.size(), n=p.size();
	int starI=-1, starJ=-1;
	while(i<m)
	{
		if(j<n&&s[i]==p[j])
		{
			i++;
			j++;
		}
		else if(j<n&&p[j]=='*')
		{
			while(j<n&&p[j]=='*')j++;
			if(j==n)return true;
			starI=i;
			starJ=j;
		}
		else if((j==n||s[i]!=p[j])&&starJ!=-1)
		{
			i=++starI;
			j=starJ;
		}else return false;
	}
	while(j<n)if(p[j++]!='*')return false;
	return true;
}

bool regularExpressionMatch(string s, string p)
{
	size_t pos=p.find("-");
	string first=p.substr(0, pos); 
	string second=p.substr(pos+1,p.size()-pos);
	if(matchHelper(s,first)&&!matchHelper(s,second))return true;
	return false;    
}

bool isMatch(string s, string p)
{
	int m=s.size();
	int n=p.size();
	vector<bool> dp(m+1);
	dp[0]=true;
	for(int j=0;j<n;j++)
	{
		if(p[j]!='*')
		{
			for(int i=m-1;i>=0;i--)
				dp[i+1]=dp[i]&&(p[j]=='?'||s[i]==p[j]);
				//dp[i]以为这dp[j-1][i]匹配成功了
		}
		else
		{
			int i=0;
			while(i<=m&&!dp[i])i++;
			for(;i<=m;i++)
				dp[i]=true;
		}
		dp[0]=dp[0]&&p[j]=='*';
	}
	return dp[m];
}

int _tmain(int argc, _TCHAR* argv[])
{
	//cout<<regularExpressionMatch("ab","a*-*b")<<endl;
	cout<<regularExpressionMatch("abababb","a*b-ba*b")<<endl;
	cout<<isMatch("abababb","a*b")<<endl;
	cout<<isMatch("abababb","ba*b")<<endl;
	return 0;
}
