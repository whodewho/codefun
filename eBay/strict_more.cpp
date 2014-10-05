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

bool strict_more(vector<int> v) {
    if (v.empty())
        return false;
    map<int, int> m;
    int max = INT_MIN;
    bool strict = false;
    for (int i = 0; i < v.size(); i++) {
        if (m.find(v[i]) == m.end()) {
            m[v[i]] = 1;
            if (m[v[i]] > max) {
                max = 1;
                strict = true;
            }
        } else {
            m[v[i]] = m[v[i]] + 1;
            if (m[v[i]] > max) {
                max = m[v[i]];
                strict = true;
            } else if (m[v[i]] == max) {
                strict = false;
            }
        }
    }

    return strict;
}

int main() {
    int A[10] = { 1, 2, 3, 4, 4, 4, 5, 5, 5, 5 };
    vector<int> wode(A, A + 10);
    cout << strict_more(wode) << endl;
    cout << "wode" << endl;
}

