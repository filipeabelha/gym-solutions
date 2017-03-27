#include <bits/stdc++.h>

int main () {
    int begin = 1;
    while (1) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        char list[60][60];
        int maxstrlen = 0;
        if (!begin) printf("\n");
        begin = 0;
        for (int i = 0; i < n; i++) {
            char str[60];
            scanf("%s", str);
            if (strlen(str) >= maxstrlen)
                maxstrlen = strlen(str);
            strcpy(list[i], str);
        }
        for (int i = 0; i < n; i++) {
            printf("%*s\n", maxstrlen, list[i]);
        }
    }
    return 0;
}
