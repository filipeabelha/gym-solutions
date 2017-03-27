#include <bits/stdc++.h>

int main () {
        int n;
        scanf("%d", &n);

        char c;
        scanf(" %c", &c);

        double matrix[12][12];
        for (int i = 0; i < 12; i++) for (int j = 0; j < 12; j++) scanf("%lf", &matrix[i][j]);

        double sum = 0;
        for (int i = 0; i < 12; i++) sum += matrix[n][i];

        if (c == 'M') sum /= 12;

        printf("%.1lf\n", sum);

        return 0;
}
