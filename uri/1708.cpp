#include <bits/stdc++.h>

int main () {
    int lap;
    int fastest, slowest;
    scanf("%d%d", &fastest, &slowest);
    for (int i = 1; i < 10000; i++) {
        int f = fastest * i;
        int s = slowest * i;
        if (s - f >= fastest) {
            lap = i + 1;
            break;
        }
    }
    printf("%d\n", lap);
    return 0;
}
