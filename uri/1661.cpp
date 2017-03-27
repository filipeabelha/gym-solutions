#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+10;
int n, v[N];
ll ans;

int main () {
    while (1) {
        ans = 0;
        scanf("%d", &n);
        if (!n) break;
        for (int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        for (int i = 0; i < n-1; i++) {
            v[i+1] += v[i];
            ans += abs(v[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
