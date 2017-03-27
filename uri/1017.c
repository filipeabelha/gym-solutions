#include <stdio.h>

int main() {
    int t, v;
    scanf("%d%d", &t, &v);
    int s = v*t;
    float qtt = s/12.0;
    printf("%.3f\n", qtt);
    return 0;
}
