#include <bits/stdc++.h>
using namespace std;

unsigned long long n;

int main () {
    while (1) {
        cin >> n;
        if (n == -1) break;
        cout << ((!n) ? 0 : n-1) << endl;
    }
}
