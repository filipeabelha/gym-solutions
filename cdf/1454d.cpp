#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;
typedef vector<int> vi;

const int N = 1e6+10;

int cmp[N];
vi pr;

void primes() {
    for (ll i = 2; i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j += i) cmp[j] = 1;
        pr.pb(i);
    }
}

map<ll, int> factorize(ll n) {
    map<ll, int> fact;
    for (int i = 0; i < pr.size() and pr[i]*pr[i] <= n; i++) {
        while (n % pr[i] == 0) {
            fact[pr[i]]++;
            n /= pr[i];
        }
    }
    if (n > 1) fact[n]++;
    return fact;
}

int t;
ll n;

int main () {
    primes();

    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        map<ll, int> f = factorize(n);
        vector <pair<int, ll> > g;
        for (auto p : f) {
            ll x = p.first;
            int y = p.second;
            g.push_back({-y, x});
        }
        sort(g.begin(), g.end());
        vector <ll> ans;
        for (auto p : g) {
            int y = -p.first;
            ll x = p.second;
            while (ans.size() < y) ans.push_back(1);
            for (int i = ans.size()-1; i >= 0 and y > 0; i--, y--) {
                ans[i] *= x;
            }
        }
        printf("%d\n", (int) ans.size());
        for (int i = 0; i < ans.size(); i++) {
            printf("%lld%c", ans[i], " \n"[i+1==ans.size()]);
        }
    }
    return 0;
}
