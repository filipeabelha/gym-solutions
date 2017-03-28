#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int x, n, maxi;
ll sum, ans;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        sum += x;
        maxi = max(maxi, x);
    }
    ans = (maxi <= sum/2) ? sum/2 : sum-maxi;
    printf("%I64d\n", ans);
    return 0;
}
