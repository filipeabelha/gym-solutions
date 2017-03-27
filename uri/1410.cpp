#include <bits/stdc++.h>
using namespace std;

#define cl(x, v) memset((x), (v), sizeof(x))

int atk[20], def[20], a, d, maxatk, pendef;

int main () {
    while (1) {
        scanf("%d%d", &a, &d);
        if (!a and !d) break;
        for (int i = 0; i < a; i++)
            scanf("%d", &atk[i]);
        for (int i = 0; i < d; i++)
            scanf("%d", &def[i]);

        sort(atk, atk+a);
        sort(def, def+d);

        maxatk = atk[0];
        pendef = def[1];
        printf("%s\n", (maxatk < pendef) ? "Y" : "N");
    }
    return 0;
}
