#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))

typedef vector <int> vi;
typedef pair <int, vi> piv;

const int INF = 0x3f3f3f3f;
const int N = 5e4;

map <vi, int> id;
vi from, to;
int x, nextid, dist[N];
priority_queue <piv> pq;

int main () {
    for (int i = 0; i < 8; i++) scanf("%d", &x), from.pb(x);
    for (int i = 0; i < 8; i++) scanf("%d", &x), to.pb(x);
    cl(dist, 63);
    id[from] = 0;
    dist[nextid++] = 0;
    pq.push(mp(0, from));
    while (!pq.empty()) {
        vi v = pq.top().nd;
        int d = -pq.top().st; pq.pop();
        if (dist[id[v]] < d) continue;
        for (int i = 0; i <= 3; i++) {
            vi u = v;
            int cost = v[i]+v[i+4];
            swap(u[i], u[i+4]);
            if (!id.count(u)) id[u] = nextid++;
            if (dist[id[u]] > dist[id[v]]+cost) {
                dist[id[u]] = dist[id[v]]+cost;
                pq.push(mp(-dist[id[u]], u));
            }
        }
        for (int i = 0; i <= 6; i++) {
            if (i == 3) continue;
            vi u = v;
            int cost = v[i]+v[i+1];
            swap(u[i], u[i+1]);
            if (!id.count(u)) id[u] = nextid++;
            if (dist[id[u]] > dist[id[v]]+cost) {
                dist[id[u]] = dist[id[v]]+cost;
                pq.push(mp(-dist[id[u]], u));
            }
        }

    }
    printf("%d\n", dist[id[to]]);
    return 0;
}
