#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, g;
    while(scanf("%d%d", &n, &g) != EOF) {
        vector<int> pro;
        vector<int> against;
        for (int i = 0; i < n; i++) {
            int pr, ag;
            scanf("%d%d", &pr, &ag);
            pro.push_back(pr);
            against.push_back(ag);
        }

        int k = 0;
        while (g > 0) {
            int wins = 0;
            for (int i = 0; i < pro.size(); i++) {
                if (pro[i] + k == against[i])
                    for (int j = 0; j <= k; j++)
                        if (g > 0) pro[i]++, g--;
                if (pro[i] > against[i]) wins++;
            }
            if (wins == pro.size()) break;
            k++;
        }

        int points = 0;
        for (int i = 0; i < pro.size(); i++) if (pro[i] == against[i]) points += 1; else if (pro[i] > against[i]) points += 3;
        printf("%d\n", points);
    }
    return 0;
}
