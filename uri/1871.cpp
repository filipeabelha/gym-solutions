#include <bits/stdc++.h>
using namespace std;

int main () {
    while (1) {
        long long a, b;
        scanf("%lld%lld", &a, &b);
        if (a == 0 and b == 0) break;
        long long sum = a+b;
        vector <int> result;
        while (sum > 0) {
            long long lastDigit = sum - 10*(sum/10);
            long long newSum = sum / 10;
            result.push_back(lastDigit);
            sum = newSum;
        }
        for (int i = result.size()-1; i >= 0; i--)
            if (result[i] != 0)
                printf("%d", result[i]);
        printf("\n");
    }
    return 0;
}
