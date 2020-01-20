#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, x, ans = 0;
int a[N], d[N];

int main () {
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 1; i < n; i++) d[i] = a[i] - a[i-1];
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (j == n or d[j] > x) {
                ans = max(ans, j-i);
                break;
            }
        }
    }
    printf("%d\n", ans);
}
