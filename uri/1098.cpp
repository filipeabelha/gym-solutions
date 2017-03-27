#include <bits/stdc++.h>

int main () {
        int add = 0;
        for (int i = 0; i <= 20; i += 2) {
                for (int j = 10; j <= 30; j += 10) {
                        float ip = i / 10.0;
                        float jp = (j + add) /10.0;
                        if (i % 10 == 0 and add % 10 == 0)      printf("I=%.0f J=%.0f\n", ip, jp);
                        else if (i % 10 != 0 and add % 10 != 0) printf("I=%.1f J=%.1f\n", ip, jp);
                        else if (i % 10 == 0)                   printf("I=%.0f J=%.1f\n", ip, jp);
                        else if (add % 10 == 0)                 printf("I=%.1f J=%.0f\n", ip, jp);
                };
                add += 2;
        };
        return 0;
}
