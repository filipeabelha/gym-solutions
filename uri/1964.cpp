#include <bits/stdc++.h>
using namespace std;

int c, va, vb, t, d, da, db;

int main () {
    scanf("%d%d%d%d%d", &c, &va, &vb, &t, &d);
    c *= 100, d *= 100, t *= 60; da = db = c-d;
    da += va*t; db += vb*t;
    da %= c; db %= c;
    if (!da) da = c; if (!db) db = c;
    printf("%s\n", (c-da)/((double) va) <= (c-db)/((double) vb) ? "Ana" : "Bia");
    return 0;
}
