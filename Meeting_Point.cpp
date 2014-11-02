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

vector<int> meetPoint(int matrix[3][4], int m, int n)
{
	vector<int> result;

	vector<int> row(m, 0);
	vector<int> col(n, 0);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(matrix[i][j])
			{
				row[i]=matrix[i][j];
				col[j]=matrix[i][j];
			}
		}
	}

	int leftPeopleNum=0, leftWalkSum=0, rightPeopleNum=0, rightWalkSum=0;
	int i=0, j=m-1;
	while(i<j)
	{
		if(leftPeopleNum+row[i]<=rightPeopleNum+row[j])
		{
			leftPeopleNum+=row[i];
			leftWalkSum=leftWalkSum+leftPeopleNum;
			i++;
		}
		else
		{
			rightPeopleNum+=row[j];
			rightWalkSum=rightWalkSum+rightPeopleNum;
			j--;
		}
	}
	result.push_back(i);

	int upPeopleNum=0, upWalkSum=0, downPeopleNum=0, downWalkSum=0;
	i=0,j=n-1;
	while(i<j)
	{
		if(upPeopleNum+col[i]<=downPeopleNum+col[j])
		{
			upPeopleNum+=col[i];
			upWalkSum=upWalkSum+upPeopleNum;
			i++;
		}
		else
		{
			downPeopleNum+=col[j];
			downWalkSum=downWalkSum+downPeopleNum;
			j--;
		}
	}
	result.push_back(j);
	return result;
}

void testMeetPoint()
{
	int a[3][4]={{0,4,0,0},{0,0,0,3},{5,0,0,0}};
	vector<int> result=meetPoint(a,3,4);
	cout<<result[0]<<" "<<result[1]<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	testMeetPoint();
	return 0;
}
