#include <bits/stdc++.h>
using namespace std;

#define cl(x, v) memset((x), (v), sizeof(x))
#define pb push_back
#define mp make_pair
#define st first
#define nd second

typedef pair <int, int> pii;
typedef pair <int, pii> piii;

char x, xx, y, yy, chr;

int vis[10][10], ans, xi, xj, yi, yj;

int da[] = {+2, +2, +1, +1, -1, -1, -2, -2};
int db[] = {+1, -1, +2, -2, +2, -2, +1, -1};

priority_queue <piii> pq;

void bfs (int a, int b, int dep) {
    if (a < 1) return;
    if (b < 1) return;
    if (a > 8) return;
    if (b > 8) return;
    vis[a][b] = 1;
    if (a == yi and b == yj) {ans = dep; return;}
    for (int i = 0; i < 8; i++) {
        int m = a+da[i];
        int n = b+db[i];
        if (!vis[m][n]) {
            pq.push(mp(-(dep+1), mp(m, n)));
            vis[m][n] = 1;
        }
    }
    while (!pq.empty()) {
        int m = pq.top().nd.st;
        int n = pq.top().nd.nd;
        int d = -pq.top().st; pq.pop();
        bfs(m, n, d);
    }
}

int main () {
    while (~scanf("%c%c%c%c%c%c", &x, &xx, &chr, &y, &yy, &chr)) {
        cl(vis, 0);
        xi = x-'`', xj = xx-'0', yi = y-'`', yj = yy-'0';
        bfs(xi, xj, 0);
        printf("To get from %c%c to %c%c takes %d knight moves.\n", x, xx, y, yy, ans);
    }
    return 0;
}
