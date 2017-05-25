#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fact[20];
string s;

int main () {
    fact[0] = 1; for (int i = 1; i <= 15; i++) fact[i] = i*fact[i-1];
    while (cin >> s and s != "0") printf("%lld\n", fact[s.size()]);
    return 0;
}
