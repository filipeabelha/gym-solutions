#include <bits/stdc++.h>
using namespace std;

string s;

int main () {
    while (getline(cin, s)) {
        int ok = 1;
        for (auto c : s) if (c == 'i') ok = 0;
        printf("%s\n", ok ? "S" : "N");
    }
}
