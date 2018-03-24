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
#define gcd(x, y) __gcd((x), (y))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll res[10][10], A[10][10], B[10],aux[10][10], n, m, ans[10];

ll fexp(ll b, ll e, ll m){
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b) % m;
        b = (b*b) % m;
        e >>= 1;
    }
    return ans;
}

int main () {
    while(scanf("%lld%lld",&n,&m) != EOF) {

    res[0][0] = 1;
    res[0][1] = 0;
    res[1][0] = 0;
    res[1][1] = 1;
    
    B[0] = 1;
    B[1] = 0;

    A[0][0] = A[1][0] = A[0][1] = 1;
    A[1][1] = 0;

    m = fexp(2, m, MOD);
    ll b = n;
    while(b > 0) {
        if (b%2 == 1) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    aux[i][j]=0;
                    for (int k = 0; k < 2; k++) {
                        aux[i][j] += (res[i][k]*A[k][j])%m;
                    }
                }
            }        
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    res[i][j] = aux[i][j];
        }
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                aux[i][j] = 0;
                for (int k = 0; k < 2; k++)
                    aux[i][j] += (A[i][k]*A[k][j])%m;
            }
        }
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                A[i][j] = aux [i][j];

        b /= 2;
    }
    for (int i = 0; i < 2; i++){
        ans[i] = 0;
        for (int j = 0; j < 2; j++){
            ans[i] += (res[i][j]*B[j])%m;
        }
    }
    printf("%lld\n",ans[1]);
    }
    return 0;
}
