#include <bits/stdc++.h>
using namespace std;

int n, m[15][15], maxx, cls, ans;
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2};
int dy[] = {-1, +1, -2, +2, +2, -2, +1, -1};

void print () {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            printf("%d ", m[i][j]);
            if (j == 9) printf("\n");
        }
    printf("\n");
}

void go (int x, int y, int h) {
    if (x < 0 or y < 0) return;
    if (m[x][y] == 0) return;
    if (m[x][y] == 1) {
        m[x][y] = 0;
        // print();
        for(int i=0; i<8; ++i)
            go(x+dx[i],y+dy[i], h+1);

        ans = min(ans, cls-h);
        m[x][y] = 1;
    }
}

int main () {
    for (int i = 1; 1; i++) {
        scanf("%d", &n);
        if (!n) break;
        memset(m, 0, sizeof(m));
        cls = 0;
        ans = 100000000;
        for (int j = 0; j < n; j++) {
            int sk, sq;
            scanf("%d%d", &sk, &sq);
            for (int k = sk; k < sk+sq; k++)
                m[j][k] = 1, cls++;
        }
        int brk = 0;
        for (int j = 0; j < 15; j++) {
            for (int k = 0; k < 15; k++)
                if (m[j][k] == 1) {
                    go(j,k,1);
                    brk = 1;
                    break;
                }
            if (brk) break;
        }
        if (ans == 1)
            printf("Case %d, 1 square can not be reached.\n", i);
        else
            printf("Case %d, %d squares can not be reached.\n", i, ans);
    }
    return 0;
}
