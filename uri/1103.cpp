#include <bits/stdc++.h>

int main () {
        while(1) {
                int h1, m1;
                int h2, m2;
                scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
                if (h1 == 0 and m1 == 0 and h2 == 0 and m2 == 0) break;
                if (m1 > m2) m2 += 60, h2 -= 1;
                if (h1 > h2) h2 += 24;

                int mr = m2 - m1;
                int hr = h2 - h1;

                printf("%d\n", mr + hr*60);
        };
        return 0;
}
