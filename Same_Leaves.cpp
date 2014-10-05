#include "stdafx.h"
#include "iostream"
#include "vector"
#include "string"
#include "map"
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <stack>

using namespace std;

struct Node{
	int val;
	vector<Node*> child;
	Node(int _v):val(_v){}
};

Node* getNextLeave(stack<Node*> &stk2)
{
	while(!stk2.empty())
	{
		Node *t2=stk2.top();
		stk2.pop();
		if(t2->child.empty())
		{
			return t2;
		}

		for(int i=t2->child.size()-1;i>=0;i--)
		{
			stk2.push(t2->child[i]);
		}
	}
	return NULL;
}

bool sameLeaves(Node *t1, Node *t2)
{
	if(!t1)return !t2;
	stack<Node*> stk1;
	stk1.push(t1);
	stack<Node*> stk2;
	stk2.push(t2);
	while(!stk1.empty())
	{
		t1=stk1.top();
		stk1.pop();
		if(t1->child.empty())
		{
			Node* nextLeave=getNextLeave(stk2);
			if(!nextLeave)return false;
			if(t1->val!=nextLeave->val)return false;
		}

		for(int i=t1->child.size()-1;i>=0;i--)
		{
			stk1.push(t1->child[i]);
		}
	}
	if(!stk2.empty())return false;
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Node *t1=new Node(1);
	Node *t2=new Node(2);
	Node* t3=new Node(3);
	Node* t4=new Node(4);
	Node* t5=new Node(5);
	t1->child.push_back(t2);
	t1->child.push_back(t3);
	t1->child.push_back(t4);
	t4->child.push_back(t5);

	Node *t6=new Node(2);
	Node *t7=new Node(2);
	Node* t8=new Node(3);
	Node* t9=new Node(4);
	Node* t10=new Node(5);
	t6->child.push_back(t7);
	t6->child.push_back(t8);
	t6->child.push_back(t9);
	//t8->child.push_back(t10);

	cout<<sameLeaves(t1, t6)<<endl;
	return 0;
}



