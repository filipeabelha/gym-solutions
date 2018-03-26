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

int n;

int main () {
    while (~scanf("%d", &n) and n > 0) {
        int c = 0;
        int p = 0;

        set <int> s;
        s.insert(50);
        for (int i = 0; i <= 20; i++) {
            s.insert(i);
            s.insert(2*i);
            s.insert(3*i);
        }

        vi v;
        for (auto x : s) v.pb(x);

        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < v.size(); j++)
                for (int k = 0; k < v.size(); k++)
                    if (v[i] + v[j] + v[k] == n) {
                        p++;
                        if (k >= j and j >= i) c++;
                    }

        if (!c) printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
        else {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, c);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, p);
        }

        for (int i = 1; i <= 70; i++) printf("*");
        printf("\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
