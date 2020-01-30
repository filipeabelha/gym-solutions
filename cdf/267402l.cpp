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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int bit[N];

void add (int p, int v) {
    for (p+=2; p<N; p += p&-p) bit[p] += v;
}

int query (int p) {
    int r = 0;
    for (p+=2; p; p -= p&-p) r += bit[p];
    return r;
}

int m, n, w, h, W[N];
vi ans[N];

priority_queue <pii> ready;
priority_queue <piii> cooldown;

int main () {
    scanf("%d%d%d%d", &m, &n, &w, &h);

    for (int i = 1; i <= m; i++) {
        scanf("%d", &W[i]);
        ready.push({W[i], i});
    }

    for (int t = 1; t <= n; t++) {
        int d;
        scanf("%d", &d);

        while (cooldown.size() and t >= -cooldown.top().st) {
            ready.push(cooldown.top().nd);
            cooldown.pop();
        }

        int diff = d - query(t);
        while (diff--) {
            if (ready.empty()) {
                printf("-1\n");
                return 0;
            }

            pii p = ready.top(); ready.pop();

            int v = p.st;
            int i = p.nd;

            add(t, 1);
            add(t+w, -1);

            ans[i].pb(t);

            cooldown.push({-(t+w+h), {v-w, i}});

            if (v-w < 0) {
                printf("-1\n");
                return 0;
            }
        }

    }

    if (query(n+1)) {
        printf("-1\n");
        return 0;
    }

    printf("1\n");
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < ans[i].size(); j++)
            printf("%d%c", ans[i][j], " \n"[j+1==ans[i].size()]);
    }

    return 0;
}
