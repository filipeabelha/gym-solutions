#include <bits/stdc++.h>

int rafael(int x, int y) {
        return 9*x*x + y*y;
}

int beto(int x, int y) {
        return 2*x*x + 25*y*y;
}

int carlos(int x, int y) {
        return -100*x + y*y*y;
}

int main() {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
                int x, y;
                scanf("%d%d", &x, &y);
                if       (rafael(x,y) > beto(x,y) and rafael(x,y) > carlos(x,y)) printf("Rafael ganhou\n");
                else if  (beto(x,y) > rafael(x,y) and beto(x,y) > carlos(x,y))   printf("Beto ganhou\n");
                else     printf("Carlos ganhou\n");
        }
        return 0;
}
