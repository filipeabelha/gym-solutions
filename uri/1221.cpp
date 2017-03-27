#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int N = 1e5+5;

int p[N], k;
vector <int> primes;

int main () {
    for (ll i = 2; i <= N; ++i) if (!p[i]) {
        for (ll j = i*i; j <= N; j+=i)
            p[j]=1;
        primes.pb(i);
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        int found = 0;
        for (ll j = 0; j < primes.size() and primes[j]*primes[j] <= k; j++) {
            if (k % primes[j] == 0) {
                printf("Not Prime\n");
                found = 1;
                break;
            }
        }
        if (!found) printf("Prime\n");
    }
    return 0;
}
