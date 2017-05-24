#include<bits/stdc++.h>
using namespace std;

const int N = 5e4+10;
int n, a[N], ans;

int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) 
        if (a[i] > min(i, a[i-1]+1)) a[i] = min(i, a[i-1]+1);

    for (int i = n; i; i--)
        if (a[i] > min(n-i+1, a[i+1]+1)) a[i] = min(n-i+1, a[i+1]+1);

    for (int i = 1; i <= n; i++) ans = max(ans, a[i]);

    printf("%d\n", ans);

    return 0;
}
