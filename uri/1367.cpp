#include <bits/stdc++.h>

int main () {
    int n;
    while(1) {
        scanf("%d", &n);
        if (n == 0) break;
        int times[100];
        int corr[100];
        memset(times, 0, sizeof(times));
        memset(corr, 0, sizeof(corr));
        char chr;
        scanf("%c", &chr);
        for (int i = 0; i < n; i++) {
            int time;
            char answer[20];
            scanf(" %c", &chr);
            scanf("%d", &time);
            scanf(" %s", answer);
            if (strcmp(answer, "correct") == 0) {
                corr[chr] = 1;
                times[chr] += time;
            } else
                times[chr] += 20;
        }
        int totaltime = 0, totalanswers = 0;
        for (int i = 0; i < 100; i++) {
            if (corr[i] == 1) {
                totaltime += times[i];
                totalanswers++;
            }
        }
        printf("%d %d\n", totalanswers, totaltime);
    }
    return 0;
}
