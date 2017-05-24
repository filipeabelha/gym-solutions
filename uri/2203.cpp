#include <bits/stdc++.h>
using namespace std;

int xa, ya, xb, yb, v, ru, rv, d;

int main () {
    while (scanf("%d%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &v, &ru, &rv) != EOF) {
        d = (xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
        printf("%s\n", sqrt((double) d)+1.5*v > ru+rv ? "N" : "Y");
    }
    return 0;
}
