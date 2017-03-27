#include <stdio.h>

int main() {
    int n, i = 2;
    scanf("%d", &n);
    for (i = 0; i < 10000; i++) {
        if (i % n == 2) printf("%d\n", i);
    }
    return 0;
}
