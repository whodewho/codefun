
#include "stdafx.h"
#include <iostream>
#include <climits>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string serialize(vector<string> strs)
{
	stringstream counter;
	stringstream s;
	for(int i=0;i<strs.size();i++)
	{
		counter<<strs[i].size()<<"_";
		s<<strs[i];
	}
	counter<<"_";
	counter<<s;
	return counter.str();
}

vector<string> deserialize(string s)
{
	vector<string> result;
	size_t split=s.find("__");
	if(split==string::npos)return result;

	string counter=s.substr(0, split);

	int sPos=split+2, countPos=0;
	string::size_type st;
	while(countPos<split)
	{
		int k=countPos;
		while(k<split&&s[k]!='_')k++;
		int itemLength=stoi(s.substr(countPos, k-countPos), &st);
		result.push_back(s.substr(sPos, itemLength));
		sPos+=itemLength;
		countPos=k;
	}
	return result;
}

void testSerialize()
{
	vector<string> strs;

	string tmp=serialize(strs);
	cout<<tmp<<endl;
	for(int i=0;i<strs.size();i++)cout<<strs[i]<<endl;
	cout<<"------------"<<endl;

	strs.push_back("");
	tmp=serialize(strs);
	cout<<tmp<<endl;
	for(int i=0;i<strs.size();i++)cout<<strs[i]<<endl;
	cout<<"-----------"<<endl;

	strs.push_back(" ");
	tmp=serialize(strs);
	cout<<tmp<<endl;
	for(int i=0;i<strs.size();i++)cout<<strs[i]<<endl;
	cout<<"-----------"<<endl;

	strs.push_back(" abcd | \t\t\0");
	tmp=serialize(strs);
	cout<<tmp<<endl;
	for(int i=0;i<strs.size();i++)cout<<strs[i]<<endl;
	cout<<"-----------"<<endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	testSerialize();
	return 0;
}

