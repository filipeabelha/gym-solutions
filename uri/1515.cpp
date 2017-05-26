#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, x, y, mini;
char chr, name[60], ans[60];

int main () {
    while (1) {
        scanf("%d%c", &n, &chr); if (!n) break;
        mini = INF;
        while (n--) {
            scanf("%s %d %d%c", name, &x, &y, &chr);
            if (x-y < mini) mini = x-y, strcpy(ans, name);
        }
        printf("%s\n", ans);
    }
    return 0;
}
