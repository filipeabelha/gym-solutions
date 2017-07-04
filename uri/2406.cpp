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

int n;
string st;

int main () {
    while (~scanf("%d", &n)) {
        while (n--) {
            int ok = 1;
            cin >> st;
            stack <char> k;
            for (int i = 0; i < st.size(); i++) {
                if (st[i] == '(') k.push(st[i]);
                if (st[i] == '[') k.push(st[i]);
                if (st[i] == '{') k.push(st[i]);
                if (st[i] == ')') {
                    if (k.empty() or k.top() != '(') ok = 0;
                    else k.pop();
                }
                if (st[i] == ']') {
                    if (k.empty() or k.top() != '[') ok = 0;
                    else k.pop();
                }
                if (st[i] == '}') {
                    if (k.empty() or k.top() != '{') ok = 0;
                    else k.pop();
                }
                if (!ok) break;
            }
            printf("%s\n", ok and k.empty() ? "S" : "N");
        }
    }
    return 0;
}
