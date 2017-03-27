#include <stdio.h>

int main() {
    int n, i, in = 0, out = 0;
    scanf("%d", &n);
    int num[10000];
    for (i = 0; i < n; i++) scanf("%d", &num[i]);
    for (i = 0; i < n; i++) {
        if (num[i] >= 10 && num[i] <= 20) {
            in++;
        } else {
            out++;
        };
    };
    printf("%d in\n%d out\n", in, out);
    return 0;
}
