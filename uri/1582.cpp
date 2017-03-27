#include <bits/stdc++.h>

long long mdc (long long x, long long y) {
        if (x % y == 0) return y; else return mdc(y, x % y);
}

int main () {
        long long a, b, c;
        while (scanf("%lld%lld%lld", &a, &b, &c) != EOF) {

                     if (a*a != b*b + c*c and
                         b*b != a*a + c*c and
                         c*c != a*a + b*b)             printf("tripla\n");
            
                else if (
                        (a*a == b*b + c*c or b*b == a*a + c*c or c*c == a*a + b*b)
                        and
                        (mdc(mdc(a,b),mdc(a,c)) == 1)
                        )                                printf("tripla pitagorica primitiva\n");

                else                                     printf("tripla pitagorica\n");
        }
        return 0;
}
