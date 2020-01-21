#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair <ll, ll> pll;

const int N = 1e6+5;

ll v[N], n;
vector <pair<pll, pll>> sides;
vector <ll> ycompress;
map <ll, ll> idy, idyr;

int bit[N];

void add (ll p, ll v) {
    for (p+=2; p<N; p += p&-p) bit[p] += v;
}

ll query (ll p) {
    ll r = 0;
    for (p += 2; p; p -= p&-p) r += bit[p];
    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for(int i = 0; i < n; i++){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b > d) swap(b, d);
        sides.pb({{a,0},{b,d}});
        sides.pb({{c,1},{b,d}});
        ycompress.pb(b);
        ycompress.pb(d);
    }
    sort(sides.begin(), sides.end());
    sort(ycompress.begin(),ycompress.end());
    int cnt = 1;

    idy[ycompress[0]] = 1;
    idyr[1] = ycompress[0];

    for(int i=1; i < ycompress.size(); i++){
        if (ycompress[i] == ycompress[i-1]) continue;
        ++cnt;
        idy[ycompress[i]] = cnt;
        idyr[cnt] = ycompress[i];
    }

    for (auto& p : sides) {
        p.nd.st = idy[p.nd.st];
        p.nd.nd = idy[p.nd.nd];
    }

    int opened = 0;

    for (int i = 0; i < sides.size(); i++){
        ll ya = sides[i].nd.st;
        ll yb = sides[i].nd.nd;
        ll x = sides[i].st.st;

        if(!sides[i].st.nd){
            add(ya, 1);
            add(yb+1, -1);
            opened++;
            if (opened >= n-1) {
                for (int j = 1; j <= cnt; j++) {
                    if (query(j) >= n-1) {
                        cout << x << " " << idyr[j] << "\n";
                        return 0;
                    }
                }
            }
        } else {
            add(ya, -1);
            add(yb+1, 1);
        }
    }
    return 0;
}
