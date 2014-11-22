#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

string operator<<(string s, size_t n)
{
    size_t length = s.size();
    if(length==0)return s;
    n=n%length;
    if(n==0)return s;
    
    size_t i=0;
    size_t j=length-1;
    while(i<j)
    {
       swap(s[i], s[j]);
       i++;
       j--; 
    }
    
    i=0;
    j=n-1;
    while(i<j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
    
    i=n;
    j=length-1;
    while(i<j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
    return s;
}

void testLeftShift_EmptyString()
{
    string s("");
    assert((s<<2)=="");
}

void testLeftShift_ShiftGreatThanLength()
{
    string s("ab");
    assert((s<<3)=="ba");
}

void testLeftShift_ShiftEqualLength()
{
    string s("ab");
    assert((s<<2)=="ab");
}

void testLeftShift_ShiftZero()
{
    string s("ab");
    assert((s<<0)=="ab");
}

void testLeftShift_Normal()
{
    string s("Microsoft");
    assert((s<<2)=="ftMicroso");
}

int main()
{
    testLeftShift_EmptyString();
    testLeftShift_ShiftGreatThanLength();
    testLeftShift_ShiftEqualLength();
    testLeftShift_ShiftZero();
    testLeftShift_Normal();
   return 0;
}
