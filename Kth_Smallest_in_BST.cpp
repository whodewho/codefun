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

void kthSmallestHelper(Node* root, int k, int &i, int &result)
{
	if(!root)return;
	kthSmallestHelper(root->left, k, i, result);
	i++;
	if(i==k){result=root->val;return;}
	if(i<k)kthSmallestHelper(root->right, k, i, result);
}

int kthSmallest(Node* root, int k)
{
	int result, i=0;
	kthSmallestHelper(root, k, i ,result);
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Node *t1=new Node(1);
	Node *t2=new Node(2);
	Node* t3=new Node(3);
	Node* t4=new Node(4);
	Node* t5=new Node(5);
	t3->left=t2;
	t3->right=t4;
	t2->left=t1;
	t4->right=t5;
	cout<<kthSmallest(t3, 5)<<endl;
	return 0;
}



