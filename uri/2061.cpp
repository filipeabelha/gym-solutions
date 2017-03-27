#include <bits/stdc++.h>

int n, m;

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        char act[50];
        scanf("%s", act);
        if (act[0] == 'f') n++;
        if (act[0] == 'c') n--;
    }
    printf("%d\n", n);
    return 0;
}
