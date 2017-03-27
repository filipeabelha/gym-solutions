#include <stdio.h>

int main() {
    int i, counter = 0, greatest = 0, position = 0;;
    for (i = 0; i < 100; i++) {
        int num;
        scanf("%d", &num);
        counter++;
        if (num > greatest) {greatest = num; position = counter;};
    }
    printf("%d\n", greatest);
    printf("%d\n", position);
    return 0;
}
