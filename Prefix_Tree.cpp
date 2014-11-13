#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node {
public:
    bool is_word;
    int count;
    vector<Node*> children;

    Node() {
        is_word = false;
        count = 0;
        for(int i = 0; i < 26; i ++) {
            children.push_back(NULL);
        }   
    }   

    void insert(string word) {
        count ++; 
        if(word.size() == 0) {
            is_word = true;
            return;
        }   
        int tmp = word[0]-'a';
        if(children[tmp] == NULL) {
            children[tmp] = new Node();
        }   
        children[tmp]->insert(word.substr(1));
    }   

    string minPrefix(string word) {
        if(word.size() == 0 || count == 1) {
            return ""; 
        }   
        string rst;
        rst.push_back(word[0]);
        rst += children[word[0]-'a']->minPrefix(word.substr(1));
        return rst;
    }   
};

int main() {
    Node* root = new Node();
    root->insert("zebra");
    root->insert("dog");
    root->insert("duck");
    root->insert("dot");
    cout << root->minPrefix("zebra") << endl;
    cout << root->minPrefix("dog") << endl;
    cout << root->minPrefix("duck") << endl;
    cout << root->minPrefix("dot") << endl;
}
