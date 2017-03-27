#include <bits/stdc++.h>

int main () {
    double sum = 0;
    int i = 0;
    while (1) {
        char line[10000];
        gets(line);
        int n;
        if (scanf("%d", &n) == EOF) {
            printf("%.1lf\n", sum/i);
            break;
        }
        sum += n;
        gets(line);
        i++;
    }
    return 0;
}
