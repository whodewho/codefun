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

using namespace std;

struct Node{
	int val;
	Node *left;
	Node *right;
	Node(int _v):val(_v),left(NULL),right(NULL){}
};

void deleteNode(Node* &root, int val)
{
	if(!root)return;
	if(root->val==val)
	{
		if(!root->left)
		{
			Node* tmp=root;
			root=root->right;
			delete tmp;
		}
		else
		{
			if(!root->left->right)
			{
				Node* tmp=root;
				root->left->right=root->right;
				root=root->left;
				delete tmp;
			}
			else
			{
				Node* runner=root->left;
				while(runner->right->right)
				{
					runner=runner->right;
				}
				Node* tmp=runner->right;
				root->val=tmp->val;
				runner->right=tmp->left;
				delete tmp;
			}
		}
		return;
	}

	Node* father=root;
	Node* dNode=NULL;
	stack<Node*> stk;
	stk.push(father);
	while(!stk.empty())
	{
		father=stk.top();
		stk.pop();

		if(father->right)
		{
			if(father->right->val==val)
			{
				dNode=father->right;
				break;
			}
			else
			{
				stk.push(father->right);
			}
		}
		if(father->left)
		{
			if(father->left->val==val)
			{
				dNode=father->left;
				break;
			}
			else
			{
				stk.push(father->left);
			}
		}
	}
	if(!dNode)return;

	if(!dNode->left)
	{
		if(father->left==dNode)
		{
			father->left=dNode->right;
			delete dNode;
		}
		else
		{
			father->right=dNode->right;
			delete dNode;
		}
	}
	else
	{
		if(!dNode->left->right)
		{
			if(father->left==dNode)
			{
				father->left=dNode->left;
			}
			else
			{
				father->right=dNode->right;
			}
			dNode->left->right=dNode->right;
			delete dNode;
		}
		else
		{
			Node* runner=dNode->left;
			while(runner->right->right)
			{
				runner=runner->right;
			}
			Node* tmp=runner->right;
			root->val=tmp->val;
			runner->right=tmp->left;
			delete tmp;
		}
	}
}

void inOrder(Node* root)
{
	if(!root)return;
	inOrder(root->left);
	cout<<root->val<<" ";
	inOrder(root->right);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Node* t1=new Node(4);
	t1->left=new Node(1);
	t1->left->left=new Node(0);
	t1->left->right=new Node(2);
	t1->left->right->right=new Node(3);
	t1->right=new Node(5);

	inOrder(t1);
	deleteNode(t1, 3);
	cout<<endl;
	inOrder(t1);

	return 0;
}



