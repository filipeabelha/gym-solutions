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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e4+10;

int n, m, x;
vector <pii> freq;

int main () {
    while (~scanf("%d%d", &n, &m) and n and m) {
        freq.clear();
        for (int i = 0; i < N; i++) freq.pb(mp(0, i));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
            scanf("%d", &x), freq[x].st--;
        sort(freq.begin(), freq.end());
        for (int i = 1; i < N; i++) if (freq[i].st == freq[1].st)
            printf("%d ", freq[i].nd);
        printf("\n");
    }
    return 0;
}
