/*
Given a set S, find all the maximal subsets whose sum <= k. For example, if S = {1, 2, 3, 4, 5} and k = 7

Output is: {1, 2, 3} {1, 2, 4} {1, 5} {2, 5} {3, 4}

Hint:

- Output doesn’t contain any set which is a subset of other.

- If X = {1, 2, 3} is one of the solution then all the subsets of X {1} {2} {3} {1, 2} {1, 3} {2, 3} are omitted.

- Lexicographic ordering may be used to solve it
*/
#include <iostream>
#include <vector>
using namespace std;

void maxSubsetHelper(vector<vector<int> > &result, vector<bool> selected, vector<int> &numbers, int i, int k, int sum, int n)
{
    if(i==n)
    {
        int j=0;
        vector<int> row;
        for(;j<n;j++)
        {
            if(selected[j])row.push_back(numbers[j]);
            else if(numbers[j]+sum<=k)break;
        }
        if(j<n)return;
        result.push_back(row);
        return;
    }
    
    if(sum<=k)
    {
        maxSubsetHelper(result, selected, numbers, i+1, k, sum, n);
        if(sum+numbers[i]<=k)
        {
            selected[i]=true;
            maxSubsetHelper(result, selected, numbers, i+1, k, sum+numbers[i], n);
        }
    }
}

vector<vector<int> > maxSubsets(vector<int> numbers, int k)
{
    vector<vector<int> > result;
    int n=numbers.size();
    vector<bool> selected(n, false);
    maxSubsetHelper(result, selected, numbers, 0, k, 0, n);
    return result;
}

int main()
{
   int A[5]={1,2,3,4,5};
   vector<int> numbers(A, A+5);
   vector<vector<int> > result=maxSubsets(numbers, 7);
   for(int i=0;i<result.size();i++)
   {
        for(int j=0;j<result[i].size();j++)
            cout<<result[i][j]<<" ";
       cout<<endl;
   }
   cout << "Hello World" << endl; 
   
   return 0;
}
