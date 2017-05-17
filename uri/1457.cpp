#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

string s;
int n, ptr, k;

ll fact (int n, int m) {
    if (n < 1) return 1;
    return n * fact(n-m, m);
}

int main () {
    scanf("%d", &n);
    while (n--) {
        cin >> s;
        ptr = 0;
        while (s[ptr] != '!') {
            ptr++;
            if (ptr == s.size()) break;
        }
        k = s.size()-ptr;
        if (k > 0) {
            s.erase(s.begin()+ptr, s.end());
            printf("%lld\n", fact(stoi(s), k));
        } else cout << s << endl;
    }
}
