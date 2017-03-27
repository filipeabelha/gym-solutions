#include <bits/stdc++.h>

using namespace std;

int main () {
    char chr;
    int brk = 0;
    while (1) {
        vector <int> track;
        int processes;
        while (1) {
            scanf("%c", &chr);
            if (chr == 10) break;
            track.push_back(chr);
        }
        scanf("%d", &processes);
        if (scanf("%c", &chr) == EOF) break;
        int count = 0;
        int result = 0;
        for (int i = 0; i < track.size(); i++) {
            if (track[i] == 87) {
                result++;
                result += ceil((double)count/processes);
                count = 0;
            } else {
                count++;
            }
        }
        if (count > 0) result += ceil((double)count/processes);
        printf("%d\n", result);
    }
    return 0;
}
