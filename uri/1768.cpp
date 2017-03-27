#include <bits/stdc++.h>

int main () {
    int n;
    while(scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i+=2) {
            for (int j = 0; j < (n-i)/2; j++)
                printf(" ");
            for (int j = 0; j < i; j++)
                printf("*");
            printf("\n");
        }
        for (int i = 0; i < (n-1)/2; i++)
            printf(" ");
        printf("*\n");
        for (int i = 0; i < (n-3)/2; i++)
            printf(" ");
        printf("***\n\n");
    }
    return 0;
}
