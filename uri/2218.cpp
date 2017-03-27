#include <bits/stdc++.h>
using namespace std;

int n, k, res;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        res = 2;
        for (int j = 2; j <= k; j++) {
            res += j;
        }
        printf("%d\n", res);
    }
    return 0;
}
