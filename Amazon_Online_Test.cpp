
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

void test1()
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

void climber_problem()
{
// 3
// 0,3,1
// 1,4,2
// 2,5,3

// 3
// 1,4,2
// 3,6,1
// 5,7,2
	int n;
	cin>>n;
	int b=0;
	vector<vector<int> > matrix(n, vector<int>(3,0));
	for(int i=0;i<n;i++)
	{
		char tmp;
		cin>>matrix[i][0]>>tmp>>matrix[i][1]>>tmp>>matrix[i][2];
		b=max(b, matrix[i][1]);
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(matrix[j][0]>matrix[j+1][0])
			{
				vector<int> tmp=matrix[j+1];
				matrix[j+1]=matrix[j];
				matrix[j]=tmp;
			}
		}
	}

	int result=0,highest=0;
	for(int i=0;i<n;i++)
	{
		highest=max(highest, matrix[i][2]);

		int j=i+1;
		int tmp=0;
		while(j<n&&matrix[j][0]<=matrix[i][1])
		{
			tmp=max(tmp, matrix[j][2]);
			highest=max(highest, matrix[i][2]);
			j++;
		}

		if(j==i+1)
		{
			result+=(2*highest);
			highest=0;
			continue;
		}

		if(tmp<matrix[i][2])
		{
			result+=(2*(matrix[i][2]-tmp));
		}
	}

	cout<<result+b<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}

	

