#include <stdio.h>

int main() {
    int v1, v2, v3, v4, v5;
    int count = 0;
    scanf("%d%d%d%d%d", &v1, &v2, &v3, &v4, &v5);
    if (v1 % 2 == 0) count++;
    if (v2 % 2 == 0) count++;
    if (v3 % 2 == 0) count++;
    if (v4 % 2 == 0) count++;
    if (v5 % 2 == 0) count++;
    printf("%d valores pares\n", count);
    return 0;
}
