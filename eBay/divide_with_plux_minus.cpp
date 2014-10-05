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

int divide(int m, int n) {
    if (n == 0)
        return NULL;
    if (m < n)
        return 0;
    int i = 1, sum = n;
    while (sum + sum <= m) {
        i = i + i;
        sum = sum + sum;
    }
    return divide(m - sum, n) + i;
}

int main() {
    cout << divide(2, 2) << endl;
    cout << "wode" << endl;
}

