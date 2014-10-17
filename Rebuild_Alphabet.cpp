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

using namespace std;

struct Node
{
	int prev[26];
	int prevNumber;
	Node()
	{
		prevNumber=0;
		for(int i=0;i<26;i++)prev[i]=0;
	}
};

string rebuildAlphabet(vector<string> s)
{
	Node nodes[26];
	for(int i=0;i<s.size();i++)
	{
		string ts=s[i];
		if(ts[1]!=ts[2]&&nodes[ts[1]-'a'].prev[ts[0]-'a']==0)
		{
			nodes[ts[1]-'a'].prev[ts[0]-'a']=1;
			nodes[ts[1]-'a'].prevNumber++;
		}
		if(ts[2]!=ts[0]&&nodes[ts[2]-'a'].prev[ts[0]-'a']==0)
		{
			nodes[ts[2]-'a'].prev[ts[0]-'a']=1;
			nodes[ts[2]-'a'].prevNumber++;
		}
		if(ts[2]!=ts[1]&&nodes[ts[2]-'a'].prev[ts[1]-'a']==0)
		{
			nodes[ts[2]-'a'].prev[ts[1]-'a']=1;
			nodes[ts[2]-'a'].prevNumber++;
		}
	}

	string result;
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(nodes[j].prevNumber==i)
			{
				result.push_back('a'+j);
				break;
			}
		}
	}
	return result;
}

vector<string> buildSubstr(string s)
{
	vector<string> result;
	for(int i=0;i<24;i++)
		for(int j=i+1;j<25;j++)
			for(int k=j+1;k<26;k++)
			{
				string tmp;
				tmp.push_back(s[i]);
				tmp.push_back(s[j]);
				tmp.push_back(s[k]);
				result.push_back(tmp);
			}
	return result;
}

void testRebuildAlphabet()
{
	string s="abcdefghijklmnopqrstuvwxyz";
	vector<string> newSubstr=buildSubstr(s);
	cout<<s<<endl;
	cout<<rebuildAlphabet(newSubstr)<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	testRebuildAlphabet();
	return 0;
}
