
#include "stdafx.h"
#include "iostream"
#include "vector"
#include "string"
#include "map"
using namespace std;


vector < int > convertMatrix(int width, int height, vector < int > matrix) {
	vector<int> result;
	if(!width||!height)return result;

	vector<int> visited(width*height, false);
	int i=0, j=0, direction=1;
	while(true)
	{
		if(!visited[i*width+j])
		{
			result.push_back(matrix[i*width+j]);
			visited[i*width+j]=true;
		}
		else
		{
			break;
		}
		
		if(direction==1)
		{
			if(j+1>=width||visited[i*width+j+1])
			{
				direction=2;
				i=i+1;
				j=j-1;
				if(j>=width||i>=height||visited[i*width+j])break;
			}
			else
			{
				j=j+1;
			}
		}
		else if(direction==2)
		{
			if(i+1>=height||j-1<0||visited[(i+1)*width+j-1])
			{
				if(j-1<0||visited[i*width+j-1])
				{
					direction=4;
					i=i-1;
				}
				else
				{
					direction=3;
					j=j-1;
				}
			}
			else
			{
				i=i+1;
				j=j-1;
			}
		}
		else if(direction==3)
		{
			if(j-1<0||visited[i*width+j-1])
			{
				direction=4;
				i=i-1;
			}
			else
			{
				j=j-1;
			}
		}
		else if(direction==4)
		{
			if(i-1<0||visited[(i-1)*width+j])
			{
				direction=1;
				j=j+1;
			}
			else
			{
				i=i-1;
			}
		}
	}
	return result;
}

void testConvertMatrix()
{
	int width=3,height=3;
	vector<int> num(width*height, 0);
	for(int i=0;i<width*height;i++)
	{
		num[i]=i+1;
		cout<<num[i]<<" ";
	}

	cout<<endl;

	vector<int> result = convertMatrix(width, height, num);

	for(int i=0;i<result.size();i++)cout<<result[i]<<" ";

}

// 3
// 0,3,1
// 1,4,2
// 2,5,3

// 3
// 1,4,2
// 3,6,1
// 5,7,2

// 5
// 1,4,1
// 2,5,3
// 3,7,2
// 6,8,3
// 9,10,2
void climber_problem()
{
	int n;
	cin>>n;
	int b=0;
	vector<vector<int> > matrix(n, vector<int>(3,0));
	for(int i=0;i<n;i++)
	{
		char highestNeighbor;
		cin>>matrix[i][0]>>highestNeighbor>>matrix[i][1]>>highestNeighbor>>matrix[i][2];
		b=max(b, matrix[i][1]);
	}

	//bubble sort with the front index
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(matrix[j][0]>matrix[j+1][0])
			{
				vector<int> highestNeighbor=matrix[j+1];
				matrix[j+1]=matrix[j];
				matrix[j]=highestNeighbor;
			}
		}
	}

	int result=0,highestSoFar=0;
	for(int i=0;i<n;i++)
	{
		highestSoFar=max(highestSoFar, matrix[i][2]);

		int j=i+1, highestNeighbor=0;
		while(j<n&&matrix[j][0]<=matrix[i][1])
		{
			highestNeighbor=max(highestNeighbor, matrix[j][2]);
			j++;
		}

		//if next no overlap, climb down from the highest peak so far to the ground
		if(j==i+1)
		{
			result+=(2*highestSoFar);
			highestSoFar=0;
			continue;
		}

		//if neighbor is lower, climb down to the lower one
		if(highestNeighbor<matrix[i][2])
		{
			result+=(2*(matrix[i][2]-highestNeighbor));
		}
	}

	cout<<result+b<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}

	

