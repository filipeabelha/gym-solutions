#include <bits/stdc++.h>

int mo, day;

int main () {
    while (scanf("%d%d", &mo, &day) != EOF) {
        int left = 0;
        if (mo == 12 and day == 25) {
            printf("E natal!\n");
            continue;
        }
        if (mo == 12 and day == 24) {
            printf("E vespera de natal!\n");
            continue;
        }
        if (mo == 12 and day > 25) {
            printf("Ja passou!\n");
            continue;
        }
        if (mo == 1) mo++, left += 31;
        if (mo == 2) mo++, left += 29;
        if (mo == 3) mo++, left += 31;
        if (mo == 4) mo++, left += 30;
        if (mo == 5) mo++, left += 31;
        if (mo == 6) mo++, left += 30;
        if (mo == 7) mo++, left += 31;
        if (mo == 8) mo++, left += 31;
        if (mo == 9) mo++, left += 30;
        if (mo == 10) mo++, left += 31;
        if (mo == 11) mo++, left += 30;
        left -= day;
        left += 25;
        printf("Faltam %d dias para o natal!\n", left);
    }
    return 0;
}
