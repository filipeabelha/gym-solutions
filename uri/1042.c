#include <stdio.h>

int main() {
    int a, b, c, d, e, f;
    scanf("%d %d %d", &a, &b, &c);
    if (a<b && a<c) d = a; else if (b<a && b<c) d = b; else d = c;
    if (a>b && a>c) f = a; else if (b>a && b>c) f = b; else f = c;
    if ((a>b && a<c)||(a<b && a>c)) e = a; else if ((b>a && b<c)||(b<a && b>c)) e = b; else e = c;
    if (a==b && a<c) {d = a; e = b; f = c;} else if (a==b && a>c) {d = c; e = a; f = b;};
    if (a==c && a<b) {d = a; e = c; f = b;} else if (a==c && a>b) {d = b; e = a; f = c;};
    if (b==c && b<a) {d = b; e = c; f = a;} else if (b==c && b>a) {d = a; e = c; f = b;};
    printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", d, e, f, a, b, c);
    return 0;
}
