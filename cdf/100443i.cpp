#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 2e4+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

char s[30];
char txa[] = "<text>";
char txb[] = "</text>";
map <string, int> id;
map <int, string> idt;
vector <vi> t(N);
int d[N], tp, cnt;
priority_queue <pair <int, string> > pq;
vector <pair <int, string> > ans;

int main(){
    while (~scanf(" %s", s)) {
        if (strcmp(s, txa) == 0) {
            cl(d, 0);
            while (1) {
                scanf(" %s", s);
                if (strcmp(s, txb) == 0) break;
                if (strlen(s) < 4) continue;
                if (!id.count(s)) {
                    id[s] = cnt;
                    idt[cnt] = s;
                    cnt++;
                }
                d[id[s]]++;
            }
            for (int i = 0; i < cnt; i++) {
                int v = d[i];
                int p = (t[i].size() ? t[i].back() : 0);
                t[i].pb(p+v);
            }
        } else {
            scanf(" %d", &tp); 
            scanf(" %*s");
            for (int i = 0; i < cnt; i++) {
                int n = t[i].size()-1;
                int r = (t[i].size() ? t[i].back() : 0);
                int l = ((t[i].size() > 7) ? t[i][n-7] : 0);
                if (r > l) pq.push(mp(r-l, idt[i]));
            }
            ans.clear();
            printf("<top %d>\n", tp);
            int k;
            while (pq.size()) {
                int x = pq.top().st;
                string w = pq.top().nd;
                pq.pop();

                k = x;

                tp--;
                if (!tp) {
                    pq.push(mp(x, w));
                    break;
                }

                ans.pb(mp(-x, w));
            }
            while (pq.size()) {
                int x = pq.top().st;
                string w = pq.top().nd;
                pq.pop();
                if (k == x) ans.pb(mp(-x, w));
            }
            sort(ans.begin(), ans.end());
            for (auto p : ans) printf("%s %d\n", p.nd.c_str(), -p.st);
            printf("</top>\n");
        }
    }
    return 0;
}
