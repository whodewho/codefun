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
	Node *left;
	Node *right;
	Node(int _v):val(_v),left(NULL),right(NULL){}
};

void duplicateHelper(Node* root, int &result, int &count, Node *&prev)
{
	if(!root)return;
	duplicateHelper(root->left, result, count, prev);

	if(prev&&prev->val==root->val)
	{
		count++;
	}
	else
	{
		count=1;
	}
	result=max(result, count);

	prev=root;
	duplicateHelper(root->right, result, count, prev);
}

int getBSTMaxDuplicate(Node* root)
{
	int result=0, count=0;
	Node* prev=NULL;
	duplicateHelper(root, result, count, prev);
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Node* t1=new Node(1);
	t1->right=new Node(2);
	t1->right->left=new Node(2);
	t1->right->left->left=new Node(2);
	t1->right->left->left->left=new Node(2);
	t1->right->right=new Node(4);
	t1->right->right->left=new Node(4);
	cout<<getBSTMaxDuplicate(t1)<<endl;
	return 0;
}



