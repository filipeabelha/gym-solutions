#include <stdio.h>

int main() {
    int n, i;
    int num[10000];
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &num[i]);
    }
    for (i=0; i<n; i++) {
        if (num[i] == 0) printf("NULL\n");
        else if (num[i] > 0 && num[i] % 2 == 0) printf("EVEN POSITIVE\n");
        else if (num[i] > 0 && num[i] % 2 != 0) printf("ODD POSITIVE\n");
        else if (num[i] < 0 && num[i] % 2 == 0) printf("EVEN NEGATIVE\n");
        else if (num[i] < 0 && num[i] % 2 != 0) printf("ODD NEGATIVE\n");
    }
    return 0;
}
