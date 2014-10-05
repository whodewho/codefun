#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <climits>
#include <memory.h>
#include <string.h>
#include <sstream>
#include <queue>
#include <stack>
#include <assert.h>
#include <map>
#include <set>
using namespace std;

class Node {
    public:
        bool leave;
        Node* vec[256];

        Node(string _str) {
            if (_str.empty()) {
                return;
            }

            leave = true;
            this->add(_str);
        }

        void add(string _str) {
            if (_str.empty())
                return;

            leave = false;
            if (vec[(int) _str[0]] == NULL) {
                vec[(int) _str[0]] = new Node(_str.substr(1));
            } else {
                vec[(int) _str[0]]->add(_str.substr(1));
            }
        }

        bool find(string _str) {
            if (vec[(int) _str[0]] == NULL) {
                if (isspace(_str[0]))
                    return true;
                return false;
            }

            return vec[(int) _str[0]]->find(_str.substr(1));
        }
};

class Tree {
    public:
        Node * root;
        Tree(vector<string> words) {
            root = new Node("");
            for (int i = 0; i < words.size(); i++)
                root->add(words[i]);
        }
};

vector<int> negative(string description, vector<string> words) {
    vector<int> result;
    Tree* tr = new Tree(words);
    int i = 0;
    while (true) {
        if (i >= description.size())
            break;

        if ((i == 0 || isspace(description[i - 1]))
                && isalpha(description[i])) {
            if (tr->root->find(description.substr(i))) {
                result.push_back(i);
            }
        }
        i++;
    }

    return result;
}

int main() {
    vector<string> words;
    words.push_back("is bad");
    words.push_back("bad");
    words.push_back("porn");
    words.push_back("sex");
    words.push_back("wordspushbackyourbed");
    string description = "porn is bad back is bad word, wordspushbackyourbed";
    vector<int> index = negative(description, words);
    for (int i = 0; i < index.size(); i++)
        cout << description.substr(index[i]) << endl;
    cout << "wode" << endl;
}

