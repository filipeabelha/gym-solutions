#include <bits/stdc++.h>
using namespace std;

int n, k;
long long num;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        num = 1;
        for (int j = 0; j < k; j++) num *= 2;
        printf("%lld\n", num-1);
    }
    return 0;
}
