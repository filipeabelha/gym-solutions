#include <bits/stdc++.h>

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x);
            if (x == 1) printf("Rolien\n");
            else if (x == 2) printf("Naej\n");
            else if (x == 3) printf("Elehcim\n");
            else if (x == 4) printf("Odranoel\n");
        }
    }
    return 0;
}
