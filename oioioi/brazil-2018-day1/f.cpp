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
typedef vector <int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

char s[N];
int sz, ok = 1;

stack <char> v;
deque <char> ans;

int main () {
    scanf("%s", s);
    sz = strlen(s);
    for (int i = 0; i < sz; i++) {
        if (s[i] == ')' and !v.empty() and v.top() != '(') ok = 0;
        if (s[i] == '}' and !v.empty() and v.top() != '{') ok = 0;
        if (s[i] == ']' and !v.empty() and v.top() != '[') ok = 0;
        if (!ok) break;

        if (s[i] == ')' and (v.empty() or v.top() == '(')) {
            if (v.empty()) ans.push_front('(');
            if (!v.empty()) v.pop();
            ans.pb(')');
        }
        if (s[i] == ']' and (v.empty() or v.top() == '[')) {
            if (v.empty()) ans.push_front('[');
            if (!v.empty()) v.pop();
            ans.pb(']');
        }
        if (s[i] == '}' and (v.empty() or v.top() == '{')) {
            if (v.empty()) ans.push_front('{');
            if (!v.empty()) v.pop();
            ans.pb('}');
        }

        if (s[i] == '(') v.push('('), ans.pb('(');
        if (s[i] == '[') v.push('['), ans.pb('[');
        if (s[i] == '{') v.push('{'), ans.pb('{');
    }
    if (ok) {
        while (v.size()) {
            if (v.top() == '(') ans.pb(')');
            if (v.top() == '[') ans.pb(']');
            if (v.top() == '{') ans.pb('}');
            v.pop();
        }
        while (ans.size()) {
            printf("%c", ans.front());
            ans.pop_front();
        }
        printf("\n");
    }
    else printf("NIE\n");
    return 0;
}
