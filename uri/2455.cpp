#include <bits/stdc++.h>
using namespace std;

int main () {
    int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d\n", a*b == c*d ? 0 : a*b < c*d ? 1 : -1);
    return 0;
}
