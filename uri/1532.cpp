#include <bits/stdc++.h>
using namespace std;

int n, v, vv, x, ok;

int main () {
    while (1) {
        scanf("%d%d", &n, &v); if (!n and !v) break; ok = 0;
        if (!n) ok = 1;
        for (int i = 1; i <= v; i++) {
            x = 0; vv = i;
            while (x <= n and vv > 0) {
                for (int j = 0; j < vv; j++) {
                    x += vv;
                    if (x == n) ok = 1;
                }
                vv--;
            }
        }
        printf("%s\n", ok ? "possivel" : "impossivel");
    }
}
