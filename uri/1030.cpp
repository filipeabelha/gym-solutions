#include <bits/stdc++.h>

using namespace std;

int main () {
    int nc;
    scanf("%d", &nc);
    for (int i = 1; i <= nc; i++) {
        int n, k;
        scanf("%d %d", &n, &k);
        vector <int> v;
        for (int j = 1; j <= n; j++) v.push_back(j);
        int pos = -1;
        int vivos = n;
        while (vivos > 1) {
            for (int z = 0; z < k; z++) do {
                    pos++;
                    if (pos == n) pos = 0;
                } while (v[pos] < 0);
            v[pos] = -1;
            vivos--;
        }
        for (int j = 0; j < n; j++) if (v[j] > 0) printf("Case %d: %d\n", i, v[j]);
    }
    return 0;
}
