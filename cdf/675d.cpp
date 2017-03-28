#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int a[N], p[N];

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);    
    map <int, int> m;
    m[a[0]] = 0;
    for (int i = 1; i < n; i++) {
        m[a[i]] = i;
        int h = -1;
        map <int, int>::iterator it = m.lower_bound(a[i]);
        if (it != m.begin()) {
            it--;
            h = it->second;
            p[i] = it->first;
        }
        it = m.lower_bound(a[i]);
        it++;
        if (it != m.end()) {
            if (it->second >= h)
                p[i] = it->first;
        }
        printf("%d ", p[i]);
    }
    return 0;
}
