#include <stdio.h>
#include <math.h>

int main() {
    int n, i, a[10000000];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    };
    for (i = 0; i < n; i++) {
        if (2015 - a[i] > 0) printf("%d D.C.\n", 2015 - a[i]);
        else printf("%d A.C.\n", abs(2015 - a[i]) + 1);
    };
    return 0;
}
