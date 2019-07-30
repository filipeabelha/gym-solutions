#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define gcd(x, y) __gcd((x), (y))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+0;
const int N = 1e5+5;

vector <vector <ll> > A, AN, B, BB, C, D;

void mul () {
    // Resizing and clearing D
    D.resize(B.size());
    for (auto& row : D) row.resize(C[0].size());
    for (auto& row : D)
        for (auto& elem : row)
            elem = 0;

    // Multiplying B*C = D
    for (int i = 0; i < D.size(); i++) {
        for (int j = 0; j < D[i].size(); j++) {
            for (int k = 0; k < B[0].size(); k++) {
                D[i][j] += B[i][k]*C[k][j];
                D[i][j] %= MOD;
            }
        }
    }
}

// Fast matrix exponential to get A^n
void getAN (ll n) {
    AN.clear();
    AN.resize(A.size());
    for (auto& row : AN) row.resize(A[0].size());

    for (int i = 0; i < AN.size(); i++)
        AN[i][i] = 1;

    ll e = n;
    while (e) {
        if (e&1) {
            B = AN;
            C = A;
            mul();
            AN = D;
        }
        B = A;
        C = A;
        mul();
        A = D;
        e >>= 1;
    }
}

int c;

int main () {

    scanf("%d", &c);
    while (c--) {
        ll k;
        scanf("%lld", &k);

        BB.clear();
        BB.resize(1);
        BB[0].resize(k);
        for (int i = 0; i < k; i++)
            scanf("%lld", &BB[0][k-1-i]);

        A.clear();
        A.resize(k);
        for (int i = 0; i < k; i++) A[i].resize(k);

        for (int i = 0; i < k; i++)
            scanf("%lld", &A[i][0]);

        for (int i = 0; i < k-1; i++)
            A[i][i+1] = 1;

        ll n;
        scanf("%lld", &n);
        n--;

        getAN(n);
        C = AN;

        B = BB;

        mul();
        printf("%lld\n", D[0].back());
    }
    return 0;
}
