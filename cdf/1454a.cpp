#include <bits/stdc++.h>
using namespace std;

int t, n;

int main () {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            printf("%d%c", (i+1)%n+1, " \n"[i+1==n]);
        }
    }

    return 0;
}
