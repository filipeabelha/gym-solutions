#include <bits/stdc++.h>

int main () {
        double matrix[12][12];
        double sum = 0;
        char type;
        scanf("%c", &type);
        for (int i = 0; i < 12; i++) for (int j = 0; j < 12; j++) scanf("%lf", &matrix[i][j]);
        for (int i = 0; i < 12; i++) for (int j = 0; j < 12; j++) if (i + j > 11) sum += matrix[i][j]; 
        if (type == 'M') sum /= 66;
        printf("%.1lf\n", sum);
        return 0;
}
