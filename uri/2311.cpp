#include <bits/stdc++.h>
using namespace std;

int n;
char chr;
string s;
double dif, x, ans;
priority_queue <double> pq;

int main () {
    scanf("%d%c", &n, &chr);
    while (n--) {
        getline(cin, s);
        ans = 0;
        scanf("%lf%c", &dif, &chr);
        for (int i = 0; i < 7; i++) {
            scanf("%lf%c", &x, &chr);
            pq.push(x);
        }
        pq.pop();
        for (int i = 0; i < 5; i++) {
            x = pq.top(); pq.pop();
            ans += x;
        }
        pq.pop();
        ans *= dif;
        cout << s;
        printf(" %.2lf\n", ans);
    }
    return 0;
}
