#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    while (scanf("%d", &n) != EOF) {
        vector <int> pts;
        int result = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            pts.push_back(1);
            for (int j = 0; j < x-1; j++) pts.push_back(0);
        }
        if (pts.size() % 3 != 0) {
            printf("0\n");
            continue;
        }
        int jump = pts.size() / 3;
        for (int i = 0; i < pts.size(); i++) {
            int a = i;
            int b = i + jump;
            int c = i + 2*jump;
            if (b > pts.size()) b -= pts.size();
            if (c > pts.size()) c -= pts.size();
            if (pts[a] and pts[b] and pts[c]) {
                result++;
                pts[a] = pts[b] = pts[c] = 0;
            }
        }
        printf("%d\n", result);
    }
    return 0;
}
