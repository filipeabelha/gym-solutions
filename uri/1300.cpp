#include <bits/stdc++.h>
using namespace std;

int n, h, m, ok;

int main () {
    while(~scanf("%d", &n)) {
        h = m = ok = 0;
        if (!n) ok = 1;
        do {
            m += 6, m %= 360;
            if (m % 30 == 0) h += 12, h %= 360;
            if (abs(h-m) == n or 360-abs(h-m) == n) ok = 1;
        } while (h or m);
        printf("%s\n", ok ? "Y" : "N");
    }
    return 0;
}
