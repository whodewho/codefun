/*
Implement a method called printNonComments() which prints out a extract of text with comments removed. 

For example, the input: 

hello /* this is a 
multi line comment */ all 

Should produce: 

hello 
all 

You have access to a method called getNextLine() which returns the next line in the input string.
*/

// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "vector"
#include "iostream"
using namespace std;

int i = 0;
vector<string> vec;

string getNextLine()
{
	return vec[i++];
}

void printNonComment()
{
	bool inComment = false, hasEnter = false;
	string s = getNextLine();
	while (!s.empty())
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (!inComment)
			{
				if (s[i] == '/'&&i + 1 < s.size() && s[i + 1] == '*')
				{
					inComment = true;
					i++;
					continue;
				}
				cout << s[i];
			}
			else
			{
				if (s[i] == '*'&&i + 1 < s.size() && s[i + 1] == '/')
				{
					inComment = false;
					i++;
					int j = i + 1;
					if (hasEnter)
						while (j < s.size() && s[j] == ' ')s.erase(s.begin() + j);
					hasEnter = false;
					continue;
				}
			}
		}
		if (!(inComment&&hasEnter))
		{
			cout << endl;
		}
		if (inComment)hasEnter = true;
		s = getNextLine();
	}
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	vec.push_back("hello /* this /*is amul");
	vec.push_back("ti line comment */ all");
	vec.push_back("");
	printNonComment();
	return 0;
}

