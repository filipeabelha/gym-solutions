#include <bits/stdc++.h>
using namespace std;

char chr;
int n1, d1, n2, d2, nr, dr;
void sum() {nr = n1*d2 + n2*d1; dr = d1*d2;}
void diff() {nr = n1*d2 - n2*d1; dr = d1*d2;}
void mult() {nr = n1*n2; dr = d1*d2;}
void div() {nr = n1*d2; dr = n2*d1;}
int abs(int a) {return (a > 0) ? a : -a;}
int mdc(int a, int b) {
    return (b > a) ? mdc(b, a) : ((a % b == 0) ? abs(b) : mdc(b, a%b));}

int main () {
    int n;
    scanf("%d%c", &n, &chr);
    for (int i = 0; i < n; i++) {
        char op;
        scanf("%d / %d %c %d / %d", &n1, &d1, &op, &n2, &d2);
        if (op == '+') sum();
        if (op == '-') diff();
        if (op == '*') mult();
        if (op == '/') div();
        if (nr > 0 and dr < 0) nr = -nr, dr = -dr;
        printf("%d/%d = %d/%d\n", nr, dr, nr/mdc(nr, dr), dr/mdc(nr, dr));
    }
    return 0;
}
