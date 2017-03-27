#include <bits/stdc++.h>
using namespace std;

int sieve[100000], n, v;
double h, d;

int main () {
    for (int i = 2; i < 95000; i++)
        if (!sieve[i])
            for (int j = 2*i; j < 95000; j += i)
                sieve[j] = 1;
    scanf("%d", &n);
    for (int i = 0; i < 10;)
        for (int j = n; i < 10; j++)
            if (!sieve[j]) v += j, i++;
    h = (double) 60000000/v;
    d = h / 24;
    printf("%d km/h\n%d h / %d d\n", v, (int) h, (int) d);
    return 0;

}
