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

string a, n;
int cnt;

int main () {
    while (cin >> a and a.size() != 1 and a[0] != '0' and ++cnt) {
        if (cnt != 1) printf("\n");
        cin >> n;
        int ans = 0;
        for (int sh = 0; sh <= n.size()-a.size(); sh++) {
            int ok = 1;
            for (int i = 0; i < a.size(); i++)
                if (n[sh+i] != a[i]) ok = 0;
            if (ok) ans = 1;
        }
        printf("Instancia %d\n", cnt);
        printf("%s\n", ans ? "verdadeira" : "falsa");
    }
    return 0;
}
