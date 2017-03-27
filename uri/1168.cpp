#include <bits/stdc++.h>

int main () {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
                char v[101];
                scanf("%s", v);
                int sum = 0;
                for (int j = 0; j < strlen(v); j++) {
                        if (v[j] == '0') sum += 6;
                        if (v[j] == '1') sum += 2;
                        if (v[j] == '2') sum += 5;
                        if (v[j] == '3') sum += 5;
                        if (v[j] == '4') sum += 4;
                        if (v[j] == '5') sum += 5;
                        if (v[j] == '6') sum += 6;
                        if (v[j] == '7') sum += 3;
                        if (v[j] == '8') sum += 7;
                        if (v[j] == '9') sum += 6;
                }
                printf("%d leds\n", sum);
        }
        return 0;
}
                        
