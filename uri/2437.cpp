#include <bits/stdc++.h>
using namespace std;

int main () {
    int xa, ya, xb, yb; scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
    printf("%d\n", abs(xa-xb)+abs(ya-yb));
    return 0;
}
