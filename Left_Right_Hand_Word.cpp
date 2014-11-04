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

enum fingerType{LEFT, RIGHT, MIX};

char leftC[256]={0};
char rightC[256]={0};

fingerType getFingerType(string s)
{
	fingerType toReturn=MIX;
	char *standard=NULL;
	for(int i=0;i<s.size();i++)
	{
		if(standard==NULL)
		{
			if(leftC[s[i]])
			{
				standard=leftC;
				toReturn=LEFT;
			}
			else
			{
				standard=rightC;
				toReturn=RIGHT;
			}
		}
		else
		{
			if(standard[s[i]]==0)return MIX;
		}
	}
	return toReturn;
}

void getLargestSmallest(vector<string> s)
{
	string leftSmallest="", leftLargest="";
	int leftSmallestLength=10000, leftLargestLength=0;
	string rightSmallest="", rightLargest="";
	int rightSmallestLength=10000, rightLargestLength=0;
	for(int i=0;i<s.size();i++)
	{
		fingerType ft=getFingerType(s[i]);
		if(ft==MIX)continue;
		else if(ft==LEFT)
		{
			if(s[i].size()>leftLargestLength)
			{
				leftLargest=s[i];
				leftLargestLength=s[i].size();
			}
			if(s[i].size()<leftSmallestLength)
			{
				leftSmallest=s[i];
				leftSmallestLength=s[i].size();
			}
		}
		else
		{
			if(s[i].size()>rightLargestLength)
			{
				rightLargest=s[i];
				rightLargestLength=s[i].size();
			}
			if(s[i].size()<rightSmallestLength)
			{
				rightSmallest=s[i];
				rightSmallestLength=s[i].size();
			}
		}
	}
	cout<<leftSmallest<<" "<<leftLargest<<endl;
	cout<<rightSmallest<<" "<<rightLargest<<endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	string leftSS="qwerasdftgzxcvb";
	string rightSS="uiopjklm;";
	for(int i=0;i<leftSS.size();i++)leftC[leftSS[i]]=1;
	for(int i=0;i<rightSS.size();i++)rightC[rightSS[i]]=1;
	vector<string> result;
	result.push_back("");
	result.push_back("as");
	result.push_back("qwer");
	result.push_back("dfj");
	result.push_back("uiopm");
	result.push_back("kli");
	getLargestSmallest(result);
	return 0;
}
