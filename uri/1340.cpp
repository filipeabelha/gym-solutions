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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, op, k;
int ansq, anspq, ansst;

int main () {
    while (~scanf("%d", &n) and n) {
        queue <int> q;
        priority_queue <int> pq;
        stack <int> st;
        ansq = anspq = ansst = 1;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &op, &k);
            if (op == 1) {
                q.push(k);
                pq.push(k);
                st.push(k);
            } else if (op == 2) {
                if (q.front() != k) ansq = 0;
                if (pq.top() != k) anspq = 0;
                if (st.top() != k) ansst = 0;
                q.pop();
                pq.pop();
                st.pop();
            }
        }
        if (ansq + anspq + ansst == 0) printf("impossible\n");
        else if (ansq + anspq + ansst > 1) printf("not sure\n");
        else if (ansq) printf("queue\n");
        else if (anspq) printf("priority queue\n");
        else if (ansst) printf("stack\n");
    }
    return 0;
}
