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

map<char, vector<char> > getChildren(vector<pair<char, char> > relation)
{
	map<char, vector<char> > toReturn;
	for(int i=0;i<relation.size();i++)
	{
		if(toReturn.find(relation[i].first)==toReturn.end())
		{
			toReturn.insert(make_pair<char, vector<char> >(relation[i].first, vector<char>()));
		}
		toReturn[relation[i].first].push_back(relation[i].second);
	}
	return toReturn;
}

char getAncestor(vector<pair<char, char> > relation)
{
	set<char> father;
	set<char> children;
	for(int i=0;i<relation.size();i++)
	{
		father.insert(relation[i].first);
		children.insert(relation[i].second);
	}
	for(set<char>::iterator it=children.begin();it!=children.end();it++)
	{
		father.erase(*it);
	}

	for(set<char>::iterator it=father.begin();it!=father.end();it++)
		return *it;
	return NULL;
}

void printTopicTreeHelper(char root, map<char, vector<char> > topics, string space)
{
	cout<<space<<root<<endl;
	for(int i=0;i<topics[root].size();i++)
	{
		printTopicTreeHelper(topics[root][i], topics, space+" ");
	}
}

void printTopicTree(vector<pair<char, char> > relation)
{
	map<char, vector<char> > topics = getChildren(relation);
	char root=getAncestor(relation);
	printTopicTreeHelper(root, topics, "");
}

void testPrintTopicTree()
{
	vector<pair<char, char> > relation;
	relation.push_back(pair<char, char>('c', 'a'));
	relation.push_back(pair<char, char>('c', 'b'));
	relation.push_back(pair<char, char>('a', 'd'));
	relation.push_back(pair<char, char>('a', 'e'));
	relation.push_back(pair<char, char>('a', 'f'));
	relation.push_back(pair<char, char>('b', 'h'));
	relation.push_back(pair<char, char>('b', 'j'));
	random_shuffle(relation.begin(), relation.end());
	printTopicTree(relation);
}

int _tmain(int argc, _TCHAR* argv[])
{
	testPrintTopicTree();
	return 0;
}
