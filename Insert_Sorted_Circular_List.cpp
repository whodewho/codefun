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

struct Node{
	int val;
	Node* next;
	Node(int _v):val(_v){}
};

void insertSortedCircularList(Node* &head, int val)
{
	if(head==NULL)
	{
		head=new Node(val);
		head->next=head;
		return;
	}

	Node* fast=head;
	Node* slow=head;
	while(true)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow)break;
	}
	fast=head;
	while(fast!=slow)
	{
		fast=fast->next;
		slow=slow->next;
	}

	Node* prev=NULL;
	int count=0;
	Node* runner=head;
	while(true)
	{
		if(val<=runner->val)
		{
			Node* tmp=new Node(val);
			if(prev==NULL)
			{
				tmp->next=head;
				head=tmp;
			}
			else
			{
				tmp->next=runner;
				prev->next=tmp;
			}
			return;
		}
		else
		{
			if(runner==fast)count++;
			if(count==2)
			{
				Node* tmp=new Node(val);
				tmp->next=runner->next;
				runner->next=tmp;
				return;
			}
			prev=runner;
			runner=runner->next;
		}
	}
}

void testNullSortedCircularList()
{
	Node* head=NULL;
	insertSortedCircularList(head, 1);
	assert(head->val==1);
}

void testOneItemInsertSortedCircularList()
{
	Node* head=new Node(1);
	head->next=head;
	insertSortedCircularList(head,2);
	assert(head->next->val==2&&head->next->next==head);
}

void testDuplicateInsertSortedCircularList()
{
	Node* head=new Node(1);
	head->next=new Node(1);
	head->next->next=head->next;
	insertSortedCircularList(head,2);
	assert(head->next->next->val==2&&head->next->next->next==head->next);
}

void testNormalInsertSortedCircularList()
{
	Node* head=new Node(1);
	head->next=new Node(2);
	head->next->next=new Node(4);
	head->next->next->next=head->next;
	insertSortedCircularList(head, 3);
	assert(head->next->next->val==3);
}

int _tmain(int argc, _TCHAR* argv[])
{
	testNullSortedCircularList();
	testOneItemInsertSortedCircularList();
	testDuplicateInsertSortedCircularList();
	testNormalInsertSortedCircularList();
	return 0;
}
