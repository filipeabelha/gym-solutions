#include <bits/stdc++.h>
using namespace std;

int main () {
        long long a, b, r1, r2;
        while(scanf("%lld %lld", &a, &b) != EOF) {
                r1 = b-a;
                r2 = a-b;
                printf("%lld\n", max(r1, r2));
        }
        return 0;
}
