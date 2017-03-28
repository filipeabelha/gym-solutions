#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

ll n, k, p, newp, l, r, ch;

priority_queue <ll> pq;
vector <string> ans;

void remove () {
    if (pq.size() == 0) {
        ans.pb("insert 0");
        return;
    }
    pq.pop();
} 

int main () {
    scanf("%I64d", &n);
    for (ll i = 0; i < n; i++) {
        char op[50], ins[50];
        scanf(" %s", op);
        if (op[0] == 'i') {
            scanf(" %I64d", &k);
            pq.push(-k);
            sprintf(ins, "insert %I64d", k);
            ans.pb(ins);
        }
        if (op[0] == 'g') {
            scanf(" %I64d", &k);
            while (pq.size() > 0 and -k < pq.top()) {
                remove();
                sprintf(ins, "removeMin");
                ans.pb(ins);
            }
            if (pq.size() == 0 or -k > pq.top()) {
                pq.push(-k);
                sprintf(ins, "insert %I64d", k);
                ans.pb(ins);
            }
            sprintf(ins, "getMin %I64d", k);
            ans.pb(ins);
        }
        if (op[0] == 'r') {
            remove();
            sprintf(ins, "removeMin");
            ans.pb(ins);
        }
    }
    printf("%I64d\n", (ll) ans.size());
    for (ll i = 0; i < ans.size(); i++)
        printf("%s\n", ans[i].c_str());
    return 0;
}
