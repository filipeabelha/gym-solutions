#include <bits/stdc++.h>

int main () {
    char a[10], b[10], c[10];
    while (scanf(" %[0-9]+%[0-9]=%[0-9]", a, b, c) != EOF){
        int x = 0, y = 0, z = 0;
        int f;
        f = 1;
        for (int i = 0; i < (int) strlen(a); i++)
            x += (a[i]-48)*f, f *= 10;
        f = 1;
        for (int i = 0; i < (int) strlen(b); i++)
            y += (b[i]-48)*f, f *= 10;
        f = 1;
        for (int i = 0; i < (int) strlen(c); i++)
            z += (c[i]-48)*f, f *= 10;
        (x+y==z)?printf("True\n"):printf("False\n");
    }
    return 0;
}
