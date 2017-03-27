#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b;

int main () {
    while (1) {
        scanf("%lld%lld", &a, &b);
        if (!a and !b) break;
        printf("%lld\n", a*b);
    }
    return 0;
}
