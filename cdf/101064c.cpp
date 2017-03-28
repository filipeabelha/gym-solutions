#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int w[N], h, wid, mini = 1e7;

int main () {
    scanf("%d%d", &h, &wid);
    for (int i = 0; i < h; i++)
        scanf("%d", &w[i]);
    for (int i = 0; i < h; i++) {
        int x;
        scanf("%d", &x);
        if (abs(wid-x-w[i]) < mini)
            mini = wid-x-w[i];
    }
    if (mini % 2 == 0)
        printf("%d\n", mini/2);
    else
        printf("%.1f\n", (float) mini/2);
    return 0;
}
