#include <bits/stdc++.h>

int main () {
        int x, y, sum = 0;
        scanf("%d%d", &x, &y);
        if (x > y) {
                int aux = x;
                x = y;
                y = aux;
        };
        for (int i = x+1; i < y; i++) if(i % 2 != 0) sum += i;
        printf("%d\n", sum);
        return 0;
}
