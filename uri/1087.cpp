#include <bits/stdc++.h>

int main () {
        while (1) {
                int x1, y1, x2, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                if (x1 == 0 and y1 == 0 and x2 == 0 and y2 == 0)       break;
                if (x1 == x2 and y1 == y2)                             {printf("0\n"); continue;};
                if (x1 == x2 or y1 == y2 or abs(x1-x2) == abs(y1-y2))  {printf("1\n"); continue;};
                printf("2\n");
        };
        return 0;
}
