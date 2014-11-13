#include <iostream>
#include<vector>
#include <string.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

int *add(int *a, int n, int b)
{
    stringstream ss;
    ss<<b;
    int m=ss.str().size();
    int i=n-1,j=m-1,carry=0;
    while(i>=0&&j>=0)
    {
        int t=a[i]+b%10+carry;
        a[i]=t%10;
        carry=t/10;
        b=b/10;
        i--;
        j--;
    }
    
    if(i>=0)
    {
       while(i>=0)
       {
           int t=a[i]+carry;
           a[i]=t%10;
           carry=t/10;
           i--;
       }
      
       if(carry)
       {
          int *result=new int[n+1];
          memcpy(result+1,a,n*sizeof(int));
          result[0]=carry;
          return result;
       }
       return a;
    }
    else
    {
        int *result=new int[m+1];
        memcpy(result+m+1-n,a,n*sizeof(int));
        while(b)
        {
           int t=b%10+carry;
           result[j+1]=t%10;
           carry=t/10;
           b/=10;
           j--;
        }

        if(carry)
        {
           result[0]=carry;
        }
        else
        {
           result=result+1;
           //delete (int *)(result-1);
        }
       return result;
    }
}

void testAdd_ALonger()
{
    int a[4]={2,3,4,5};
    int b=45;
    int *result=add(a,4,b);
    for(int i=0;i<4;i++)
        cout<<result[i]<<" ";
    cout<<endl;
}

void testAdd_ALongerWithCarry()
{
    int a[4]={9,5};
    int b=5;
    int *result=add(a,2,b);
    for(int i=0;i<3;i++)
        cout<<result[i]<<" ";
    cout<<endl;
}

void testAdd_BLonger()
{
    int a[1]={9};
    int b=12;
    int *result=add(a,1,b);
    for(int i=0;i<2;i++)
        cout<<result[i]<<" ";
    cout<<endl;
}

void testAdd_BLongerWithCarry()
{
    int a[1]={9};
    int b=92;
    int *result=add(a,1,b);
    for(int i=0;i<3;i++)
        cout<<result[i]<<" ";
    cout<<endl;
}

int main()
{
   testAdd_ALonger();
   testAdd_ALongerWithCarry();
   testAdd_BLonger();
   testAdd_BLongerWithCarry();
   return 0;
}
