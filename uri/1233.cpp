#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e5+5;

int p[N], n;
vi primes;

int main() {
    for (ll i = 2; i <= N; ++i) if (!p[i]) {
        for (ll j = i*i; j <= N; j+=i)
            p[j]=1;
        primes.pb(i);
    }

    while (~scanf("%d", &n)) {
        int ind=0, ans=n;
        ll pf=primes[0];
        while (pf * pf <= n) {
            if (n%pf==0) ans-=ans/pf;
            while (n%pf==0) n/=pf;
            pf = primes[++ind];
        }
        if (n!=1) ans-=ans/n;
        printf("%d\n", (int)ans/2);
    }

    return 0;
}
