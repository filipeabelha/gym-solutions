#include <bits/stdc++.h>

int main () {
    char t = 'N';
    int a[4];
    scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
    
    int max, med, min;

    max = 0;
    med = 0;
    min = 101;

    for (int i = 0; i < 4; i++) if (i != 0 && a[i] > max)                 max = a[i];
    for (int i = 0; i < 4; i++) if (i != 0 && a[i] < min)                 min = a[i];
    for (int i = 0; i < 4; i++) if (i != 0 && a[i] != max && a[i] != min) med = a[i];

    if (max < med + min) t = 'S'; 

    max = 0;
    med = 0;
    min = 101;

    for (int i = 0; i < 4; i++) if (i != 1 && a[i] > max)                 max = a[i];
    for (int i = 0; i < 4; i++) if (i != 1 && a[i] < min)                 min = a[i];
    for (int i = 0; i < 4; i++) if (i != 1 && a[i] != max && a[i] != min) med = a[i];

    if (max < med + min) t = 'S'; 
    
    max = 0;
    med = 0;
    min = 101;

    for (int i = 0; i < 4; i++) if (i != 2 && a[i] > max)                 max = a[i];
    for (int i = 0; i < 4; i++) if (i != 2 && a[i] < min)                 min = a[i];
    for (int i = 0; i < 4; i++) if (i != 2 && a[i] != max && a[i] != min) med = a[i];

    if (max < med + min) t = 'S'; 
    
    max = 0;
    med = 0;
    min = 101;

    for (int i = 0; i < 4; i++) if (i != 3 && a[i] > max)                 max = a[i];
    for (int i = 0; i < 4; i++) if (i != 3 && a[i] < min)                 min = a[i];
    for (int i = 0; i < 4; i++) if (i != 3 && a[i] != max && a[i] != min) med = a[i];

    if (max < med + min) t = 'S'; 

    printf("%c\n", t);

    return 0;
}
