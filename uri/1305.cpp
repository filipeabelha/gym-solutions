#include <bits/stdc++.h>
using namespace std;

int main () {
    char chr;
    while (1) {
        int noloop = 1;
        int numint[50];
        int numfrac[50];
        int cutfrac[50];
        memset(numint, 0, sizeof(numint));
        memset(numfrac, 0, sizeof(numfrac));
        memset(cutfrac, 0, sizeof(cutfrac));
        int numintc = 0;
        int numfracc = 0;
        int cutfracc = 0;
        int brk = 0;
        while (1) {
            scanf("%c", &chr);
            if (chr == '.') {
                brk = 1;
                break;
            }
            if (chr == 10)
                break;
            numint[numintc] = chr-48;
            numintc++;
        }
        numint[numintc] = -1;
        if (brk)
            while (1) {
                scanf("%c", &chr);
                if (chr == 10) break;
                numfrac[numfracc] = chr-48;
                numfracc++;
            }
        scanf("%c", &chr);
        scanf("%c", &chr);
        while (1) {
            scanf("%c", &chr);
            if (chr == 10) break;
            cutfrac[cutfracc] = chr-48;
            cutfracc++;
            noloop = 0;
        }
        if (noloop) break;
        int numfracIsGreater = 0;
        int k = 0;
        while (1) {
            if (numfrac[k] == cutfrac[k]) {
                k++;
                continue;
            }
            if (numfrac[k] > cutfrac[k]) {
                numfracIsGreater = 1;
                break;
            } else
                break;
        }
        vector <int> result;
        int zerounblock = 0;
        for (int i = 0; i < 50; i++) {
            if (numint[i] > 0)
                zerounblock = 1;
            if (zerounblock) {
                if (numint[i] == -1) {
                    if (numfracIsGreater)
                        result[result.size()-1]++;
                    break;
                } else
                    result.push_back(numint[i]);
            }
        }
        if (zerounblock == 0) {
            if (numfracIsGreater)
                result.push_back(1);
            else
                result.push_back(0);
        }
        for (int i = 0; i < result.size(); i++) {
            printf("%d", result[i]);
        }
        printf("\n");
    }
    return 0;
}
