#include <stdio.h>

int main() {
    int x, y; float s;
    scanf("%d %d", &x, &y);
    while (y <= 0) {
        scanf("%d", &y);
    }
    s = (2*x + y - 1)*(y/2.0);
    printf("%.0f\n", s);
    return 0;
}
