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

struct Range{
	int left;
	int right;
	Range(int _left, int _right):left(_left), right(_right){}
};

struct Node{
	Range* self;
	int level;
	char* address;
	vector<Node *> child;
	Node(Range* _self, int _level, char* _address){
		self=_self;
		level=_level;
		address=_address;
	}
};

struct IPtoAddress{
	Node* root;
	IPtoAddress()
	{
		root=new Node(new Range(-1, -1), -1, NULL);
	}

	void add(Node* root, int level, vector<int> first, vector<int> second, char* address)
	{
		int i=0;
		for(;i<root->child.size();i++)
		{
			if(second[level]<=root->child[i]->self->left)break;
		}

		if(i==root->child.size())
		{
			//4-5, add 4-5
			if(i-1>=0&&first[level]==root->child[i-1]->self->left&&second[level]==root->child[i-1]->self->right)
			{
				if(level<3)add(root->child.back(), level+1, first, second, address);
			}
			//4-4, add 5-x
			else
			{
				root->child.push_back(new Node(new Range(first[level], second[level]), level, level==3?address:NULL));
				if(level<3)add(root->child.back(), level+1, first, second, address);
			}
		}
		else if(second[level]==root->child[i]->self->left)
		{
			//4-4 4-y, add x-4
			if(first[level]==root->child[i]->self->left&&second[level]==root->child[i]->self->right)
			{
				if(level<3)add(root->child[i], level+1, first, second, address);
			}
			else
			{
				//4-5, add x-4
				root->child.insert(root->child.begin()+i, new Node(new Range(first[level], second[level]), level, level==3?address:NULL));
				if(level<3)add(root->child[i], level+1, first, second, address);
			}
		}
		else
		{
			//5-y, add 3-4
			if(i==0)
			{
				root->child.insert(root->child.begin(), new Node(new Range(first[level], second[level]), level, level==3?address:NULL));
				if(level<3)add(root->child[i], level+1, first, second, address);
			}
			else
			{
				//3-4, 5-7, add 3-4
				if(first[level]==root->child[i-1]->self->left&&second[level]==root->child[i-1]->self->right)
				{
					if(level<3)add(root->child[i-1], level+1, first, second, address);
				}
				else
				{
					//3-4, 6-7, add 4-5
					root->child.insert(root->child.begin()+i, new Node(new Range(first[level], second[level]), level, level==3?address:NULL));
					if(level<3)add(root->child[i], level+1, first, second, address);
				}
			}
		}
	}

	char* query(Node* root, int level, vector<int> ip)
	{
		if(root->child.empty())return NULL;

		int i=0;
		for(;i<root->child.size();i++)
		{
			if(ip[level]<=root->child[i]->self->right)break;
		}

		if(i==root->child.size())
		{
			return NULL;
		}
		else 
		{
			if(ip[level]==root->child[i]->self->right)
			{
				char* toReturn = level==3?root->child[i]->address:query(root->child[i], level+1, ip);
				if(toReturn!=NULL)return toReturn;

				if(i+1<root->child.size()&&root->child[i+1]->self->left==ip[level])
				{
					return query(root->child[i+1], level+1, ip);
				}
			}
			else
			{
				if(ip[level]>=root->child[i]->self->left)
				{
					return level==3?root->child[i]->address:query(root->child[i], level+1, ip);
				}
				return NULL;
			}		
		}
		return NULL;
	}
};

vector<int> stringToVector(string ip)
{
	istringstream iss(ip);
	vector<int> tokens;
	string buf;
	string::size_type sz;
	while(getline(iss, buf, '.'))
	{
		int tmp=stoi(buf, &sz);
		tokens.push_back(tmp);
	}
	return tokens;
}

void testITA(){
	IPtoAddress* ita = new IPtoAddress();
	char *beijing="Beijing";
	char *shanghai="Shanghai";

	ita->add(ita->root, 0, stringToVector("10.4.3.4"), stringToVector("10.4.9.20"), beijing);
	ita->add(ita->root, 0, stringToVector("10.4.20.25"), stringToVector("10.7.30.25"), beijing);
	ita->add(ita->root, 0, stringToVector("10.4.20.27"), stringToVector("10.7.30.100"), beijing);
	ita->add(ita->root, 0, stringToVector("25.25.25.25"), stringToVector("29.29.29.29"), shanghai);

	cout<<ita->query(ita->root, 0, stringToVector("10.4.3.4"))<<endl;
	char* tmp=ita->query(ita->root, 0, stringToVector("10.4.20.24"));
	if(tmp!=NULL)cout<<tmp<<endl;
	else cout<<"not found"<<endl;

	tmp=ita->query(ita->root, 0, stringToVector("10.5.20.24"));
	if(tmp!=NULL)cout<<tmp<<endl;
	else cout<<"not found"<<endl;

	tmp=ita->query(ita->root, 0, stringToVector("25.26.26.26"));
	if(tmp!=NULL)cout<<tmp<<endl;
	else cout<<"not found"<<endl;

	tmp=ita->query(ita->root, 0, stringToVector("15.26.26.100"));
	if(tmp!=NULL)cout<<tmp<<endl;
	else cout<<"not found"<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	testITA();
	return 0;
}
