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
typedef vector<ll> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

vector <vll> A, AN, B, C, D;
ll n;

void mul () {
    D.resize(B.size());
    for (auto& row : D) row.resize(C[0].size());
    for (auto& row : D)
        for (auto& elem : row)
            elem = 0;

    for (int i = 0; i < D.size(); i++) {
        for (int j = 0; j < D[i].size(); j++) {
            for (int k = 0; k < B[0].size(); k++) {
                D[i][j] += B[i][k]*C[k][j];
                D[i][j] %= MOD;
            }
        }
    }
}

void getAN (ll e) {
    AN.clear();

    A.clear();
    A.resize(4);
    A[0] = {16,1, 0, 0};
    A[1] = {9, 0, 1, 0};
    A[2] = {4, 0, 0, 1};
    A[3] = {1, 0, 0, 0};

    AN.resize(A.size());
    for (auto& row : AN) row.resize(A[0].size());

    for (int i = 0; i < AN.size(); i++)
        AN[i][i] = 1;

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

ll g (ll n) {
    if (n < 0) return 0;
    getAN(n);
    B.resize(1);
    B[0] = {4388, 265, 16, 1};
    C = AN;
    mul();

    return D[0].back();
}


int main () {
    cin >> n;

    ll k = n/10;

    ll ans = (g(k) + g(k-1) + g(k-2) + g(k-3) +
        (n%10 < 5)*g(k-4)) % MOD;

    cout << ans << endl;

    return 0;
}
