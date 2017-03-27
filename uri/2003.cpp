#include <bits/stdc++.h>

int main () {
    int h, m;
    while(scanf("%d:%d", &h, &m) != EOF) {
        m += 60*(h-7);
        if (m < 0) m = 0;
        printf("Atraso maximo: %d\n", m);
    }
    return 0;
}
