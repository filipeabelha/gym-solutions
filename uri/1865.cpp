#include <bits/stdc++.h>

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char name[10000];
        scanf("%s %*d", name);
        if (strcmp(name, "Thor") == 0) printf("Y\n"); else printf("N\n");
    }
    return 0;
}
