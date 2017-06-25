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
typedef vector<vi> vii;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;

const int N = 1e7+10;
const int M = 3501;

int cmp[N];
vi p;

void primes() {
    for (ll i = 2; i <= N; ++i) if (!cmp[i]) {
        for (ll j = i*i; j <= N; j+=i) cmp[j]=1;
        p.pb(i);
    }
}

int n;

int main () {
    primes();
    while (~scanf("%d", &n) and n) {
        vi v;
        for (int i = 0; i < n; i++) v.pb(i);
        int ind = -1;
        for (int i = 0; i < N; i++) {
            if (v.size() == 1) {
                printf("%d\n", v[0]+1);
                break;
            }
            ind = (ind + p[i]) % v.size();
            v.erase(v.begin()+ind); ind--;
        }
    }
    return 0;
}
