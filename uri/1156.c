#include <stdio.h>

int main() {
    float s = 1;
    float i, j = 2;
    for (i = 3; i <= 39; i = i+2) {
        s = s + (i/j);
        j = j*2;
    }
    printf("%.2f\n", s);
    return 0;
}
