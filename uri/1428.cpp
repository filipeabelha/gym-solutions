#include <bits/stdc++.h>
using namespace std;

int tc, x, y;

int main () {
    scanf("%d", &tc); while (tc--) {
        scanf("%d%d", &x, &y);
        x -= 2; y -= 2;
        x += (3-x%3)%3; y += (3-y%3)%3;
        printf("%d\n", x*y/9);
    }
    return 0;
}
