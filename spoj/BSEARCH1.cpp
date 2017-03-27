#include <bits/stdc++.h>

using namespace std;

#define pb push_back

vector <int> v;

int x, l, m, r;

int main () {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        v.pb(x);
    }
    for (int i = 0; i < q; i++) {
        scanf("%d", &x);
        l = 0;
        r = v.size()-1;
        while (l < r) {
            m = (l+r)/2;
            if (v[m] >= x) r = m;
            else l = m+1;
        }
        if (v[l] == x) printf("%d\n", l);
        else printf("-1\n");
    }
    return 0;
}

