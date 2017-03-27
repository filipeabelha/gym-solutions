#include <bits/stdc++.h>

using namespace std;

int main () {
    while (1) {
        int n;
        scanf("%d", &n);
        if (!n) break;
        vector <int> h;
        h.push_back(n);
        int maxi = n;
        while (1) {
            int last = h[h.size()-1];
            if (last > maxi) maxi = last;
            if (last == 1) break;
            if (last % 2 == 0) h.push_back(last/2);
            else h.push_back(3*last+1);
        }
        printf("%d\n", maxi);
    }
    return 0;
}
