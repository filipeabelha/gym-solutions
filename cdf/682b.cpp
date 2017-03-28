#include <bits/stdc++.h>

using namespace std;

int k, n, cnt = 1, last;
multiset <int> s;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        s.insert(k);
    }
    for (multiset<int>::iterator it=s.begin(); it!=s.end(); ++it) {
        int v = *it;
        if (v >= cnt) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
