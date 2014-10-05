//============================================================================
// Name        : Come.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
 * 2.// Input  -> "I have  36 books, 40 pens2, and 1 notebook."
// Output -> "I evah  36 skoob, 40 2snep, dna 1 koobeton."
 */
string smart_reverse(string s) {
    if (s.empty() || s.size() == 1)
        return s;
    int i = 0;
    while (true) {
        if (i == s.size())
            break;

        while (ispunct(s[i]) || isspace(s[i]))
            i++;
        int prev = i;
        bool number = true;
        while (i < s.size() && !ispunct(s[i]) && !isspace(s[i])) {
            if (!isdigit(s[i]))
                number = false;
            i++;
        }
        if (i > prev && !number)
            reverse(s.begin() + prev, s.begin() + i);
    }

    return s;
}

int main() {
    cout << smart_reverse("I have  36 12345688888x, 40 pens2, and 1 notebook.")
        << endl;
    return 0;
}

