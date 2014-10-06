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

using namespace std;

struct Node{
	int val;
	Node *left;
	Node *right;
	Node(int _v):val(_v),left(NULL),right(NULL){}
};

string encode(string s)
{
	int n=s.size();
	if(!n)return "";
	stringstream os;
	for(int i=0;i<n;i++)
	{
		int j=i+1;
		while(j<n&&s[i]==s[j])j++;
		if(i!=0)os<<"*";
		os<<(j-i)<<s[i];
		i=j-1;
	}
	return os.str();
}

string decode(string s)
{
	int n=s.size();
	stringstream os;
	if(!n)return "";

	for(int i=0;i<s.size();i++)
	{
		int j=i+1;
		while(j<n&&s[j]!='*')j++;

		if(j+1<n&&s[j+1]=='*')j++;
		string countStr=s.substr(i, j-2-i+1);
		string::size_type sz;
		int count=stoi(countStr, &sz);
		string tmpStr(count, s[j-1]);
		os<<tmpStr;
		i=j;
	}
	return os.str();
}

int _tmain(int argc, _TCHAR* argv[])
{
	string s=encode("22288888888888***4");
	cout<<s<<endl;
	cout<<decode(s)<<endl;
	return 0;
}



