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

/*
	两个数组，同一组数的全排列，连接相同的两个数，线有交点，删去最少的点儿，让所有的线不相交
	index[]的作用是，遍历v2，记录最大不想交线集合的长度为[i]时，index[i]为在v1里最优的index，这个数组是升序的，所以二分
	跟数的大小梅关系
*/
int minErase(vector<int> &vec1, vector<int> &vec2)
{
	map<int, int> m;
	int n=vec1.size();
	for(int i=0;i<n;i++)
		m[vec1[i]]=i;
	vector<int> index(n+1,-1);
	int end=0;
	for(int i=0;i<n;i++)
	{
		int l=1, h=end;
		while(l<=h)
		{
			int middle=(l+h)/2;
			if(m[vec2[i]]<index[middle])
				h=middle-1;
			else l=middle+1;
		}

		if(l<=end&&m[vec2[i]]<index[l])
		{
			index[l]=m[vec2[i]];//更新
		}
		else
		{
			end++;
			index[end]=m[vec2[i]];//添在尾部
		}
	}
	return n-end;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int A[5]={2,3,1,5,4};
	int B[5]={5,4,3,1,2};
	vector<int> v1(A, A+5);
	vector<int> v2(B, B+5);
	cout<<minErase(v1, v2)<<endl;
	return 0;
}


