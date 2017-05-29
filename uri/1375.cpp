#include <bits/stdc++.h>
using namespace std;

#define cl(x, v) memset((x), (v), sizeof(x))

const int N = 1e3+10;
int v[N], n, car, var, notok;

int main () {
    while (1) {
        scanf("%d", &n); if (!n) break;
        notok = 0; cl(v, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &car, &var);
            if (i+var > n or i+var < 1) notok = 1;
            else if (v[i+var]) notok = 1;
            else v[i+var] = car;
        }
        if (notok) printf("-1\n");
        else for (int i = 1; i <= n; i++)
            printf("%d%s", v[i], i == n ? "\n" : " ");
    }
    return 0;
}
