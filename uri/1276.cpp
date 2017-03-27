#include <bits/stdc++.h>

using namespace std;

int main () {
    char chr;
    int brk = 0;
    int consec10 = 0;
    while (1) {
        int freq[130];
        memset(freq, 0, sizeof(freq));
        while (1) {
            if (scanf("%c", &chr) == EOF) brk = 1;
            if (chr == 10) {
                consec10++;
                break;
            }
            consec10 = 0;
            if (freq[chr] == 0) freq[chr]++;
        }
        if (brk) break;
        if (consec10 == 2) {
            printf("\n");
        } else {
            int notfirst = 0;
            int print = 0;
            int ind = 97;
            int elem = freq[ind];
            vector <int> interval;
            while (1) {
                if (print) {
                    int last = interval.size() - 1;
                    if (notfirst) printf(", ");
                    printf("%c:%c", interval[0], interval[last]);
                    notfirst = 1;
                    interval.erase(interval.begin(), interval.begin()+last+1);
                    print = 0;
                } else if (elem == 1) {
                    interval.push_back(ind);
                    ind++;
                    elem = freq[ind];
                    continue;
                } else {
                    if (interval.size() > 0) print = 1;
                    ind++;
                    elem = freq[ind];
                    if (ind > 125) break;
                    continue;
                }
            }
            printf("\n");
        }
    }
    return 0;
}
