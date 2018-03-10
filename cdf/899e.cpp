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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

int n;
int v[N];
set <piii> a, b;
int ans;
priority_queue <piii> pq;

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    int c = 1;
    int e = v[1];
    int k = 1;
    for (int i = 2; i <= n; i++) {
        if (v[i] != e) {
            a.insert({k, {c, e}});
            b.insert({-c, {k, e}});
            c = 1;
            e = v[i];
            k = i;
        }
        else c++;
    }
    a.insert({k, {c, e}});
    b.insert({-c, {k, e}});

    for (auto p : b) {
        p.st    *= -1;
        p.nd.st *= -1;
        pq.push(p);
    }

    while (pq.size()) {
        piii p = pq.top(); pq.pop();
        p.st    *= -1;
        p.nd.st *= -1;
        if (!b.count(p)) continue;
        ans++;

        piii q = {p.nd.st, {-p.st, p.nd.nd}};
        auto it = a.lower_bound(q);
        if (it != a.begin() and it != a.end()) {
            auto ix = it; ix--;
            auto iy = it; iy++;
            if (iy != a.end() and (*ix).nd.nd == (*iy).nd.nd) {
                int z = (*ix).nd.st + (*iy).nd.st;
                piii u = {(*iy).st, {(*iy).nd.st, (*iy).nd.nd}};
                piii v = {-(*iy).nd.st, {(*iy).st, (*iy).nd.nd}};
                a.erase(u);
                b.erase(v);
                u = {(*ix).st, {(*ix).nd.st, (*ix).nd.nd}};
                v = {-(*ix).nd.st, {(*ix).st, (*ix).nd.nd}};
                a.erase(u);
                b.erase(v);
                u.nd.st = z;
                v.st = -z;
                a.insert(u);
                b.insert(v);
                v.st    *= -1;
                v.nd.st *= -1;
                pq.push(v);
            }
        }
        a.erase(q);
        b.erase(p);
    }
    printf("%d\n", ans);


    return 0;
}

