#include <bits/stdc++.h>
using namespace std;

#define cl(x, v) memset((x), (v), sizeof(x))

int tc, x, m, v[15], maxi, imaxi;

int main () {
    scanf("%d", &tc); while (tc--) {
        cl(v, 0); maxi = imaxi = 0;
        scanf("%d%d", &x, &m);
        for (int i = 0; i < m; i++) scanf("%d", &x), v[x]++;
        for (int i = 1; i <= 10; i++)
            if (v[i] > maxi) maxi = v[i], imaxi = i;
        printf("%d\n", 2*maxi > m ? imaxi : -1);
    }
    return 0;
}
