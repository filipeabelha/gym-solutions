#include <bits/stdc++.h>
using namespace std;

int tc, t, d;

int main () {
    while (scanf("%d", &tc) != EOF) {
        double maxi = 0;
        for (int i = 1; i <= tc; i++) {
            scanf("%d%d", &t, &d);
            if ((double)d/t > maxi)
                maxi = (double)d/t, printf("%d\n", i);
        }
    }
    return 0;
}
