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

using namespace std;

struct Node{
	int val;
	Node* next;
	Node(int _v):val(_v){}
};

void insert(Node* &head, int val)
{
	if(!head){
		head=new Node(val);
		return;
	}

	if(head->val>=val)
	{
		Node* tmp=new Node(val);
		tmp->next=head;
		head=tmp;
		return;
	}

	Node* fastRunner=head;
	Node* slowRunner=head;
	while(true)
	{
		fastRunner=fastRunner->next;
		fastRunner=fastRunner->next;
		slowRunner=slowRunner->next;
		if(fastRunner==slowRunner)break;	
	}

	Node* cross=head;
	while(cross!=slowRunner)
	{
		cross=cross->next;
		slowRunner=slowRunner->next;
	}

	bool inCircle=false;
	Node* runner=head;
	while(runner->next->val<val)
	{
		if(runner==cross)
		{
			if(inCircle)
			{
				//insert before cross
				Node* prevCross=cross;
				while(prevCross->next!=cross)
				{
					prevCross=prevCross->next;
				}
				Node* tmp=new Node(val);
				tmp->next=cross;
				prevCross->next=tmp;
				return;
			}
			else inCircle=true;
		}
		runner=runner->next;
	}

	Node* tmp=new Node(val);
	tmp->next=runner->next;
	runner->next=tmp;
}

void testInsert()
{
	Node* head=new Node(1);
	head->next=new Node(2);
	head->next->next=new Node(2);
	head->next->next->next=head->next;
	insert(head, 0);
	insert(head, 1);
	insert(head, 2);
	insert(head, 3);
	insert(head, 4);
}

int _tmain(int argc, _TCHAR* argv[])
{
	testInsert();
	return 0;
}


