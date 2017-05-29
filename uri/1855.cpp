#include <bits/stdc++.h>
using namespace std;

const int N = 1e2+10;

int vis[N][N], x, y;
char m[N][N], chr;

int go (int a, int b, int da, int db) {
    vis[a][b]++;
    if (vis[a][b] == 3 or !a or !b or a > x or b > y) return 0;
    if      (m[a][b] == '*') return 1;
    if      (m[a][b] == '^') go(a-1, b, -1, 0);
    else if (m[a][b] == 'v') go(a+1, b, 1, 0);
    else if (m[a][b] == '>') go(a, b+1, 0, 1);
    else if (m[a][b] == '<') go(a, b-1, 0, -1);
    else if (m[a][b] == '.') go(a+da, b+db, da, db);
}

int main () {
    scanf("%d%c%d%c", &y, &chr, &x, &chr);
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) scanf("%c", &m[i][j]);
        scanf("%c", &chr);
    }
    printf("%s\n", go(1,1,0,0) ? "*" : "!");
    return 0;
}
