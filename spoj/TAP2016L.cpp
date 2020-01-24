#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, k;
int v[N];

int main () {
    while (~scanf("%d%d", &n, &k)) {
        int m = 0;
        int j = 0;
        for (int i = 1; i <= k; i++) {
            scanf("%d", &v[i]);
            if (m < v[i]) {
                m = v[i];
                j = i;
            }
        }

        if (m > n) {
            printf("N\n");
            continue;
        }

        if (k == 1) {
            printf("S\n");
            continue;
        }

        int l = j-1;
        int r = j+1;

        int ok = 1;
        if (v[l] == v[r]) ok = 0;

        while (l >= 1) {
            if (v[l] != v[l+1]-1 and v[l] != v[l+1]-2) ok = 0;
            if (v[l+1] == 1 or v[l+1] == 2) ok = 0;
            l--;
        }

        while (r <= k) {
            if (v[r] != v[r-1]-1 and v[r] != v[r-1]-2) ok = 0;
            if (v[r-1] == 1 or v[r-1] == 2) ok = 0;
            r++;
        }

        printf("%s\n", ok ? "S" : "N");

    }
}
