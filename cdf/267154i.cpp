#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5+5;
 
int n, x, minmod = 0x3f3f3f3f, ans = 0;
int v[N];
 
int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    scanf("%d", &x);
    for (int i = 1; i <= n; i++) {
        if (minmod > (x%v[i])) {
            minmod = (x%v[i]);
            ans = v[i];
        }
    }
    printf("%d\n", ans);
    return 0;
 
}
