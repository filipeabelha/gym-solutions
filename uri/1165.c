#include <stdio.h>
#include <math.h>

int main() {
    int i, j, n, conj[101];
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &conj[i]);
        int counter = 0;
        for (j = 2; j < abs(conj[i]); j++) {
            if (conj[i] % j == 0) counter = 1;
        }
        if (counter == 1) {
            printf("%d nao eh primo\n", conj[i]);
        } else if (counter == 0) {
            printf("%d eh primo\n", conj[i]);
        }
    }
    return 0;
}
