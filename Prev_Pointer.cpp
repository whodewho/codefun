#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

char * prevPointer(char* src, char *p)
{
	if(!src||!p||src>=p)return 0;
	if(p-1==src)return src;
	char *q=p;
	while(q-2!=src&&(int(*(q-2))&128)!=0)
	{
		q--;
	}
	if((p-q)%2==0)return p-1;
	return p-2;
}

void testPrevPointer_NullPointer()
{
	assert(prevPointer(NULL, NULL)==NULL);

	char* src="a";
	assert(prevPointer(src, NULL)==NULL);

	assert(prevPointer(NULL, src)==NULL);
}

void testPrevPointer_PIsSecondByte()
{
	char *src="ab";
	assert(prevPointer(src, src+1)==src);
}

void testPrevPointer_ReturnPrevByte()
{
	char *src="abcde";
	assert(prevPointer(src, src+4)==src+3);
}

void testPrevPointer_ReturnByteBeforePrevByte()
{
	char *src="ab\u0444de";
	assert(prevPointer(src, src+4)==src+2);
	src="ab\u0444\u0444de";
	assert(prevPointer(src, src+6)==src+4);
	src="ab\u0444\u0444\u0444de";
	assert(prevPointer(src, src+4)==src+2);
}

int main()
{
	testPrevPointer_NullPointer();
	testPrevPointer_PIsSecondByte();
	testPrevPointer_ReturnPrevByte();
	testPrevPointer_ReturnByteBeforePrevByte();
	return 0;
}