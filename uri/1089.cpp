#include <bits/stdc++.h>

int main () {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        int h[10050], sum = 0;
        for (int i = 0; i < n; i++) scanf("%d", &h[i]);
        for (int i = 1; i < n-1; i++) {
            if (h[i] > h[i-1] and h[i] > h[i+1]) sum++;
            if (h[i] < h[i-1] and h[i] < h[i+1]) sum++;
        }
        if (h[0] > h[n-1] and h[0] > h[1]) sum++;
        if (h[0] < h[n-1] and h[0] < h[1]) sum++;
        if (h[n-1] > h[0] and h[n-1] > h[n-2]) sum++;
        if (h[n-1] < h[0] and h[n-1] < h[n-2]) sum++;
        printf("%d\n", sum);
    }
    return 0;
}

