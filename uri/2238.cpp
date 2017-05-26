#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, ans = -1;
set <int> s;

int main () {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    for (int i = 1; i*i <= c; i++) if (!(c%i)) s.insert(i), s.insert(c/i);
    for (int i = 1; i*i <= d; i++) if (!(d%i)) s.erase(i), s.erase(d/i);
    for (auto i : s) if (i%a) s.erase(i);
    for (auto i : s) if (!(i%b)) s.erase(i);
    if (s.size()) for (auto i : s) {ans = i; break;}
    printf("%d\n", ans);
    return 0;
}
