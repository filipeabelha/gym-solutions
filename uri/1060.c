#include <stdio.h>

int main() {
    float v1, v2, v3, v4, v5, v6;
    int count = 0;
    scanf("%f%f%f%f%f%f", &v1, &v2, &v3, &v4, &v5, &v6);
    if (v1 > 0) count++;
    if (v2 > 0) count++;
    if (v3 > 0) count++;
    if (v4 > 0) count++;
    if (v5 > 0) count++;
    if (v6 > 0) count++;
    printf("%d valores positivos\n", count);
    return 0;
}
