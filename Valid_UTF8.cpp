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

int getWordWidth(char* p)
{
  int t=*p;
  int count=0;
  while(t&128)
  {
    t=t<<1;
    count++;
  }
  if(count==0)count=1;
  return count;
}

bool isValidContinuation(char *p)
{
  int t=*p;
  return (t&128)!=0&&(t&64)==0;
}

bool isValidUTF8(char *p)
{
  if(!p)return false;
  int n=strlen(p),i=0;
  while(i<n)
  {
    int count=getWordWidth(p+i);
    for(int j=1;j<count;j++)
      if(i+j>=n||!isValidContinuation(p+i+j))
        return false;
    i=i+count;
  }
  return true;
}

void testIsValidUTF8_NULLPointer()
{
  assert(isValidUTF8(NULL)==false);
}

void testIsValidUTF8_OneByte()
{
  char* p="\x00";
  assert(isValidUTF8(p)==true);
  p="\x0A";
  assert(isValidUTF8(p)==true);
  p="\xC0";
  assert(isValidUTF8(p)==false);
}

void testIsValidUTF8_TwoByte()
{
  char* p="\x04\x00";
  assert(isValidUTF8(p)==true);
  p="\xC0\xA0";
  assert(isValidUTF8(p)==true);
  p="\xC0\xC0";
  assert(isValidUTF8(p)==false);
  p="\x00\xC0";
  assert(isValidUTF8(p)==true);
  p="\x01\xC0";
  assert(isValidUTF8(p)==false);
}

void testIsValidUTF8_FiveByte()
{
  char* p="\xFA\xA0\xA0\xA0\xA0";
  assert(isValidUTF8(p)==true);
  p="\xFA\xA0\x00\xA0\xA0";
  assert(isValidUTF8(p)==false);
}

void testIsValidUTF8_NineByte()
{
  char* p="\xFA\xA0\xA0\xA0\xA0\xA0\xA0\xA0\01";
  assert(isValidUTF8(p)==true);
  p="\xFA\xA0\xA0\xA0\xA0\xA0\xA0\xA0\xC1";
  assert(isValidUTF8(p)==false);
}

int _tmain(int argc, _TCHAR* argv[])
{
  testIsValidUTF8_OneByte();
  testIsValidUTF8_TwoByte();
  testIsValidUTF8_FiveByte();
  testIsValidUTF8_NineByte();
  return 0;
}
