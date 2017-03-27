#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
#define cl(x, v) memset((x), (v), sizeof(x))

const int N = 25;

int tc, n, dgts[N];
ll x, m[N][N];

int calcDgts (ll x) {
    int ans = 0;
    while (x > 9) x /= 10, ans++;
    return ans;
}

int main () {
    scanf("%d", &tc);
    for (int t = 0; t < tc; t++) {
        cl(dgts, 0);

        scanf("%d", &n);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                scanf("%llu", &x);
                m[i][j] = x*x;
                dgts[j] = max(dgts[j], calcDgts(m[i][j]));
            }

        printf("Quadrado da matriz #%d:\n", t+4);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int spac = dgts[j] - calcDgts(m[i][j]);
                for (int s = 0; s < spac; s++)
                    printf(" ");
                printf("%llu", m[i][j]);
                if (j != n-1) printf(" ");
            }
            printf("\n");
        }
        if (t != tc-1) printf("\n");
    }
    return 0;
}
