#include <stdio.h>

int main() {
    int n, r1, r2, r3, r4, r5, correct = 0;
    scanf("%d", &n);
    scanf("%d %d %d %d %d", &r1, &r2, &r3, &r4, &r5);
    if (r1 == n) correct++;
    if (r2 == n) correct++;
    if (r3 == n) correct++;
    if (r4 == n) correct++;
    if (r5 == n) correct++;
    printf("%d\n", correct);
    return 0;
}
