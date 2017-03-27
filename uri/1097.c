#include <stdio.h>

int main() {
    int i, j, c = 0;
    for (i = 1; i <= 9; i = i+2) {
        for (j = 7+c; j >= 5+c; j = j-1) printf("I=%d J=%d\n", i, j);
        c = c+2;
    }
    return 0;
}
