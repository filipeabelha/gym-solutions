#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll k, cont;

int main () {
    while(~scanf("%lld", &k)) {
        ll xx[10005], yy[10005];
        xx[0] = 2*k;
        yy[0] = 2*k;
        cont = 1;
        for (ll x = 2*k-1; x > k; x--)
            if (k*x*(x-k) > 0 and (k*x) % (x-k) == 0) {
                xx[cont] = x;
                yy[cont] = (k*x)/(x-k);
                cont++;
            }
        printf("%lld\n", cont);
        for (ll i = cont-1; i >= 0; i--)
            printf("1/%lld = 1/%lld + 1/%lld\n", k, yy[i], xx[i]);
    }
    return 0;
}
