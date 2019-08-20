#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef unsigned long long ll;

const int N = 1e5+5;

ll st[4*N], v[N];
deque <ll> lazy[4*N];

void push (int p, int l, int r) {
    while (lazy[p].size()) {
        ll x = lazy[p].front(); lazy[p].pop_front();
        if (x) {
            st[p] += (r-l+1)*x;
            if (l != r) {
                if (lazy[2*p].size() and lazy[2*p].back() > 0) {
                    ll k = lazy[2*p].back();
                    lazy[2*p].pop_back();
                    lazy[2*p].push_back(x+k);
                } else lazy[2*p].push_back(x);

                if (lazy[2*p+1].size() and lazy[2*p+1].back() > 0) {
                    ll k = lazy[2*p+1].back();
                    lazy[2*p+1].pop_back();
                    lazy[2*p+1].push_back(x+k);
                } else lazy[2*p+1].push_back(x);
            }
        } else {
            st[p] = 0;
            if (l != r) {
                lazy[2*p].clear();
                lazy[2*p].push_back(0);

                lazy[2*p+1].clear();
                lazy[2*p+1].push_back(0);
            }
        }
    }
}


ll query (int p, int l, int r, int i, int j) {
    push(p, l, r);
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return st[p];
    ll x = query(2*p, l, (l+r)/2, i, j);
    ll y = query(2*p+1, (l+r)/2+1, r, i, j);
    return x+y;
}

void update (int p, int l, int r, int i, int j, ll k) {
    push(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        if (lazy[p].size() and lazy[p].back() > 0) {
            ll x = lazy[p].back();
            lazy[p].pop_back();
            lazy[p].push_back(x+k);
        } else lazy[p].push_back(k);
        push(p, l, r);
        return;
    }
    update(2*p, l, (l+r)/2, i, j, k);
    update(2*p+1, (l+r)/2+1, r, i, j, k);
    if (l != r) st[p] = st[2*p] + st[2*p+1];
}

ll n, q, o, l, r, x, ans;

int main () {
    scanf("%llu%llu", &n, &q);

    while (q--) {
        scanf("%llu%llu%llu", &o, &l, &r);
        if (o == 1) {
            scanf("%llu", &x);
            update(1, 1, n, l, r, x);
        } else {
            ans += query(1, 1, n, l, r);
            printf("%llu\n", ans);
            update(1, 1, n, l, r, 0);
        }
    }
    return 0;
}
