#include "stdafx.h"
#include "iostream"
#include "vector"
#include "string"
#include "map"
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

vector<vector<int> > makeAscendingMatrix(int m, int n)
{
	vector<vector<int> > result(m, vector<int>(n));

	srand(time(NULL));
	for(int i=0;i<m;i++)
	{
		int last=0;
		for(int j=0;j<n;j++)
		{
			int tmp=rand()%(1000)+1;
			result[i][j]=last+tmp;
			last=result[i][j];
		}
	}
	return result;
}

struct heapCompare{
	bool operator()(pair<int, int> &p1, pair<int, int> &p2)
	{
		return p1.first>p2.first;
	}
}myHeapCompare;

int getKthSmallestWithHeap(vector<vector<int> > matrix, int m, int n, int k)
{
	vector<pair<int, int> > heap;
	for(int i=0;i<m;i++)
	{
		heap.push_back(make_pair<int, int>(matrix[i][0], i));
		matrix[i].erase(matrix[i].begin());
	}
	make_heap(heap.begin(), heap.end(), myHeapCompare);

	for(int i=0;i<k-1;i++)
	{
		pair<int, int> curr=heap.front();
		pop_heap(heap.begin(), heap.end(), myHeapCompare);
		heap.pop_back();

		if(matrix[curr.second].empty())continue;

		heap.push_back(make_pair<int, int>(matrix[curr.second][0], curr.second));
		push_heap(heap.begin(), heap.end(), myHeapCompare);
		matrix[curr.second].erase(matrix[curr.second].begin());
	}

	return heap.front().first;
}

void updateDividPoint(vector<vector<int> > matrix, vector<int> head, vector<int> tail, int m, int n, int dividPoint, int &smallerThanDividPointSum, vector<int> &allDividPoint)
{
	for(int i=0;i<m;i++)
	{
		if(head[i]>tail[i])continue;
		int l=head[i], h=tail[i];
		while(l<=h)
		{
			int m=(l+h)/2;
			if(matrix[i][m]>dividPoint)h=m-1;
			else if(matrix[i][m]<dividPoint)l=m+1;
			else
			{
				l=m+1;
			}
		}
		allDividPoint[i]=l;
		smallerThanDividPointSum+=(l-head[i]);
	}
}

int recursiveHelper(vector<vector<int > > matrix, vector<int> head, vector<int> tail, int m, int n, int k)
{
	if(k==1)
	{
		int result=INT_MAX;
		for(int i=0;i<m;i++)
		{
			if(head[i]>tail[i])continue;
			result=min(matrix[i][head[i]], result);
		}
		return result;
	}

	int dividIndex=0, dividLength=-1;
	for(int i=0;i<m;i++)
	{
		int tmp=tail[i]-head[i];
		if(tmp>dividLength)
		{
			dividIndex=i;
			dividLength=tmp;
		}
	}

	if(dividLength==1)
	{
		//single column, bad divide point might not decrease problem size
		//so, there is a bug, it turns to be a one dimention select algorithm
	}

	int middle=head[dividIndex]+(tail[dividIndex]-head[dividIndex])/2;
	int dividPoint=matrix[dividIndex][middle];
	vector<int> allDividPoint(m);
	int smallerThanDividPointSum=0;
	updateDividPoint(matrix, head, tail, m, n, dividPoint, smallerThanDividPointSum, allDividPoint);

	if(smallerThanDividPointSum<k)
	{
		for(int i=0;i<m;i++)
		{
			if(head[i]>tail[i])continue;
			head[i]=allDividPoint[i];
		}
		return recursiveHelper(matrix, head, tail, m, n, k-smallerThanDividPointSum);
	}
	else if(smallerThanDividPointSum>k)
	{
		for(int i=0;i<m;i++)
		{
			if(head[i]>tail[i])continue;
			tail[i]=allDividPoint[i]-1;
		}
		return recursiveHelper(matrix, head, tail, m, n, k);
	}
	else
	{
		int result=INT_MIN;
		for(int i=0;i<m;i++)
		{
			if(head[i]>tail[i])continue;
			result=max(matrix[i][allDividPoint[i]-1], result);
		}
		return result;
	}
}

int getKthSmallestRecursive(vector<vector<int> > matrix, int m, int n, int k)
{
	vector<int> head(m, 0);
	vector<int> tail(m, n-1);
	return recursiveHelper(matrix, head, tail, m, n, k);
}

void testGetKth()
{
	int m=10, n=1, k=7;
	vector<vector<int> > matrix=makeAscendingMatrix(m, n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	vector<int> tmp;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			tmp.push_back(matrix[i][j]);
	sort(tmp.begin(), tmp.end());
	cout<<tmp[k-1]<<endl;

	cout<<getKthSmallestRecursive(matrix, m, n, k)<<endl;
	cout<<getKthSmallestWithHeap(matrix, m, n, k)<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	testGetKth();
	return 0;
}



