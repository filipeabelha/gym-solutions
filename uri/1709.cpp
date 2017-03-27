#include <bits/stdc++.h>

int main () {
    int n;
    scanf("%d", &n);
    int pos = 2;
    int count = 1;
    while (pos != 1) {
        if (pos > n/2) pos = n - (n - pos)*2 - 1; else pos = pos*2;
        count++;
    }
    printf("%d\n", count);
    return 0;
}

