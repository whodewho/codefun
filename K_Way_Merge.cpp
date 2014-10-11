
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

struct Node{
	int data;
	int index;
	Node(int _data, int _index):data(_data), index(_index){}
};

struct MyCompare{
	bool operator()(const Node& n1, const Node& n2)
	{
		return n1.data>n2.data;
	}
};

vector<int> kWayMerge(vector<vector<int> > num)
{
	priority_queue<Node, vector<Node>, MyCompare> q;
	int n=num.size();
	vector<int> index(n, 0);
	vector<int> result;
	while(true)
	{
		if(q.empty())
		{
			for(int i=0;i<n;i++)
			{
				if(index[i]<num[i].size())
				{
					Node tmp(num[i][index[i]], i);
					q.push(tmp);
					index[i]++;
				}
			}
		}
		if(q.empty())break;

		Node front=q.top();
		q.pop();
		result.push_back(front.data);
		if(index[front.index]<num[front.index].size())
		{
			Node tmp(num[front.index][index[front.index]], front.index);
			index[front.index]++;
			q.push(tmp);
		}
	}
	return result;
}

void testKWayMerge(int n)
{
	vector<vector<int> > nums;
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		vector<int> tmp;
		for(int j=0;j<i;j++)
		{
			if(j==0)tmp.push_back(rand()%50);
			else tmp.push_back(tmp[j-1]+rand()%50);
		}
		nums.push_back(tmp);
	}
	vector<int> result= kWayMerge(nums);
	for(int i=0;i<result.size();i++)cout<<result[i]<<" ";
}

int _tmain(int argc, _TCHAR* argv[])
{
	testKWayMerge(10);
	return 0;
}


