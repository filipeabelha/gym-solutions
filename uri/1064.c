#include <stdio.h>

int main() {
    float v1, v2, v3, v4, v5, v6;
    int count = 0;
    float sum = 0;
    scanf("%f%f%f%f%f%f", &v1, &v2, &v3, &v4, &v5, &v6);
    if (v1 > 0) {count++; sum = sum + v1;};
    if (v2 > 0) {count++; sum = sum + v2;};
    if (v3 > 0) {count++; sum = sum + v3;};
    if (v4 > 0) {count++; sum = sum + v4;};
    if (v5 > 0) {count++; sum = sum + v5;};
    if (v6 > 0) {count++; sum = sum + v6;};
    printf("%d valores positivos\n", count);
    printf("%.1f\n", sum/count);
    return 0;
}
