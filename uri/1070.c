#include <stdio.h>

int main() {
    int val, i, count;
    scanf("%d", &val);
    for (i = val+1; i <= val+11; i = i+2) {
        printf("%d\n", i);
    };
    return 0;
}
