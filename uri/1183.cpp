#include <bits/stdc++.h>

int main () {
        float matrix[12][12];
        float sum = 0;
        char type;
        scanf("%c", &type);
        for (int i = 0; i < 12; i++) for (int j = 0; j < 12; j++) scanf("%f", &matrix[i][j]);
        for (int i = 0; i < 12; i++) for (int j = 0; j < 12; j++) if (i < j) sum += matrix[i][j]; 
        if (type == 'M') sum /= 66;
        printf("%.1f\n", sum);
        return 0;
}
