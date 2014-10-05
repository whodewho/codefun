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

void calc_prime(int inp) {
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(3);

    int counter = 4;

    while (arr.size() < inp) {
        if (counter % 2 != 0 && counter % 3 != 0) {
            int temp = 4;
            while (temp * temp <= counter) {
                if (counter % temp == 0)
                    break;
                temp++;
            }
            if (temp * temp > counter) {
                arr.push_back(counter);
            }
        }
        counter++;
    }

    cout << "finish" << arr[inp - 1] << endl;
}

int main() {

    for (int i = 2; i <= 100; i++)
        calc_prime(i);
    cout << "wode" << endl;
}

