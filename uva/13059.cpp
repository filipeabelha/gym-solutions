#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;

int main () {
    while (~scanf("%lld", &n)) {
        ll matches = 0;
        while (1) {
            if (n % 2 == 0) {
                matches += n/2;
                n = n/2;
            } else {
                matches += n/2;
                n = n/2 + 1;
            }
            if (n == 1) break;
        }
        printf("%lld\n", matches);
    }
    return 0;
}
