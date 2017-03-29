#include <bits/stdc++.h>
using namespace std;

int n, x;

int main () {
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            printf("%d\n", 2*x-1 - (x%2==0));
        }
    }
    return 0;
}
