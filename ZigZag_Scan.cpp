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

void zigzagScan(vector<vector<int> > matrix)
{
    int m=matrix.size();
    if(!m)return;
    int n=matrix[0].size();
    if(!n)return;
    int direction=0;
    for(int k=0;k<m+n;k++)
    {
		int i, j;
        if(direction==0)
        {
            if(k<=m-1)
            {
                i=k;
                j=0;
            }
            else
            {
                i=m-1;
                j=k-(m-1);
            }
            while(i>=0&&j<=n-1)
                 cout<<matrix[i--][j++]<<" ";
        }
        else
        {
            if(k<=n-1)
            {
                i=0;
                j=k;
            }
            else
            {
               i=k-(n-1);
               j=n-1;
            }
            while(i<=m-1&&j>=0)
                cout<<matrix[i++][j--]<<" ";
        }
        direction=!direction;
    }
}



int _tmain(int argc, _TCHAR* argv[])
{
	int m=5, n=3, number=0;
	vector<vector<int> > matrix(m, vector<int>(3));
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			matrix[i][j]=number++;
	zigzagScan(matrix);
	return 0;
}

//O(N*N)
public void printZigzagForm(int[][] a, int length) {  
 
    int i=0,j=0;  
 
    while(i < length){  
 
        System.out.print(a[i][j] + " -> ");  
 
        if(i==length-1){  
            i = j+1; j = length-1;  
        }  
        else if(j==0){  
            j = i+1;   
            i = 0;  
        }  
        else {  
            i++;  
            j--;  
        }  
    }  
 
    System.out.println();  
}
