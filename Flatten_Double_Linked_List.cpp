/*
Given a doubly linked list, besides the next and previous pointers, each 
element has a child pointer, which may or may not point to a separate doubly
linked list. These child lists may have one or more children of their own. 
Now do the following:

a.    Flattern this multilevel data structure
b.    Restore the original structure from the flatterned structure

e.g.

L1 --> L2 --> L3 --> L7 --> L8
                     |
                     v
                    L4 --> L5-->L6


WIll be flattened to
L1 --> L2 --> L3 -->L4 -->L5-->L6-->L7-->L8
*/    

// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "vector"
#include "iostream"
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* child;
    Node(int _v) :val(_v),next(NULL),child(NULL){}
};

Node * flatten(Node * curr, Node * tail = NULL, Node * parent = NULL) {
    if (!curr) return tail;

    if (tail)
        tail->next = curr;

    tail = curr;
    Node * next = curr->next;

    if (curr->child)
        tail = flatten(curr->child, tail, next ? curr : parent);
    else if (!next)
        curr->child = parent;

    return flatten(next, tail, parent);
}

void restore(Node * curr) {
    while (curr) {
        Node * next = curr->next;

        if (curr->child) {
            curr->next = NULL;
            if (curr->child != next) {
                curr->child->next = next;
                curr->child = NULL;
            }
        }

        curr = next;
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    vector<Node*> vec(6);
    for (int i = 0; i < 6; i++)
        vec[i] = new Node(i);
    vec[0]->next = vec[1];
    vec[1]->next = vec[2];
    vec[1]->child = vec[3];
    vec[3]->child = vec[4];
    vec[3]->next = vec[5];

    flatten(vec[0], NULL, NULL);
    Node* runner = vec[0];
    while (runner)
    {
        cout << runner->val << "=>";
        runner = runner->next;
    }

    cout << endl;
    restore(vec[0]);
    cout << vec[1]->child->val << endl;
    cout << vec[3]->child->val << endl;
    return 0;
}

