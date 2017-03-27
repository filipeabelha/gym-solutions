#include <stdio.h>

int main() {
    int h, m, s, t;
    scanf("%d", &t);

    h = t/3600;
    t = t - h*3600;

    m = t/60;
    t = t - m*60;

    s = t;

    printf("%d:%d:%d\n", h, m, s);
    return 0;
}
