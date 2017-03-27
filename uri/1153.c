#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    int fat(x) {
        if (x==1) {return 1;} else {return x*fat(x-1);};
    }
    printf("%d\n", fat(x));
    return 0;
}
