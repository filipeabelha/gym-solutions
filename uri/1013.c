#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int maior(m, n) {
        return (m+n+abs(m-n))/2;
    }
    int x = maior(maior(a,b),maior(b,c));
    printf("%d eh o maior\n", x);
    return 0;
}
