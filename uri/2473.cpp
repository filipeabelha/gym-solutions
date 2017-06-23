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

int x, ans;
set <int> s;

int main () {
    for (int i = 0; i < 6; i++)
        scanf("%d", &x), s.insert(x);
    for (int i = 0; i < 6; i++) {
        scanf("%d", &x);
        if (s.count(x)) ans++;
    }
    printf("%s\n", ans == 6 ? "sena" :
                   ans == 5 ? "quina" :
                   ans == 4 ? "quadra" :
                   ans == 3 ? "terno" : "azar");
    return 0;
}
