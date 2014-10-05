// Problems.cpp : Defines the entry point for the console application.
/*
Given an array of positive integers that represents possible points a team could score in an individual play.
Now there are two teams play against each other. Their final scores are S and S'. 
How would you compute the maximum number of times the team that leads could have changed? 
For example, if S=10 and S'=6. The lead could have changed 4 times:
Team 1 scores 2, then Team 2 scores 3 (lead change); 
Team 1 scores 2 (lead change), Team 2 score 0 (no lead change); 
Team 1 scores 0, Team 2 scores 3 (lead change); 
Team 1 scores 3, Team 2 scores 0 (lead change); 
Team 1 scores 3, Team 2 scores 0 (no lead change).
*/

#include "stdafx.h"
#include "iostream"
#include "vector"
using namespace std;

int solve(int s1, int s2, vector<int> &A, int c)
{
	if(s1<0||s2<0)return -1;
	else if(s1==0&&s2==0)return c;

	int result=-1;
	for(int i=0;i<A.size();i++)
		for(int j=0;j<A.size();j++)
		{
			if(A[i]==0&&A[j]==0)continue;
			bool change=(s1-A[i]-(s2-A[j]))<0&&s1-s2>0||(s1-A[i]-(s2-A[j]))>0&&s1-s2<0;
			int subResult=solve(s1-A[i], s2-A[j], A, c+(change?1:0));
			if(subResult>result)result=subResult;
		}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int A[3]={0,2,3};
	vector<int> vec(A, A+3);
	cout<<solve(10,6,vec,0)<<endl;
	cout<<"wode"<<endl;
	return 0;
}

