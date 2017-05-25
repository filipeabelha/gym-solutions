#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int vis[N], x;

int main () {
    int a, b; scanf("%d%d", &a, &b);
    while (b--) scanf("%d", &x), vis[x] = 1;
    while (a--) scanf("%d", &x), printf("%d\n", 1-vis[x]), vis[x] = 1;
    return 0;
}
