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

vector<pair<int, int> > joinHelper(vector<pair<int, int> > one, vector<pair<int, int> > two)
{
	vector<pair<int, int> > result;
	int i=0, j=0;
	while(i<one.size()&&j<two.size())
	{
		if(two[j].second<one[i].first)j++;
		else if(two[j].first>one[i].second)i++;
		else if(two[j].second<=one[i].second)
		{
			result.push_back(pair<int, int>(max(one[i].first, two[j].first), two[j].second));
			j++;
		}
		else
		{
			result.push_back(pair<int, int>(max(one[i].first, two[j].first), one[i].second));
			i++;
		}
	}
	return result;
}

vector<pair<int, int> >join(vector<vector<pair<int, int> > > matrix, int l, int h)
{
	if(l==h-1)return matrix[l];
	int m=l+(h-l)/2;
	vector<pair<int, int>> one=join(matrix, l, m);
	vector<pair<int, int>> two=join(matrix, m, h);
	return joinHelper(one, two);
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<pair<int, int> > > matrix;
	vector<pair<int, int> > tmp;
	tmp.push_back(pair<int, int>(1,7));
	tmp.push_back(pair<int, int>(12,18));
	tmp.push_back(pair<int, int>(23,40));
	tmp.push_back(pair<int, int>(41,100));
	matrix.push_back(tmp);
	tmp.clear();
	tmp.push_back(pair<int, int>(0,0));
	tmp.push_back(pair<int, int>(1,2));
	tmp.push_back(pair<int, int>(8,19));
	matrix.push_back(tmp);
	tmp.clear();
	tmp.push_back(pair<int, int>(15,26));
	tmp.push_back(pair<int, int>(42,47));
	matrix.push_back(tmp);
	tmp.clear();
	tmp.push_back(pair<int, int>(17,200));
	matrix.push_back(tmp);
	vector<pair<int, int > > result=join(matrix,0,matrix.size());
	for(int i=0;i<result.size();i++)
		cout<<"["<<result[i].first<<" "<<result[i].second<<"]"<<endl;
	return 0;
}
