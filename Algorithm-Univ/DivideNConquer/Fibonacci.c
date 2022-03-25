#include <stdio.h>
#include <stdlib.h>

int count;

int rFib(int n) {
    count++;
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else 
        return (rFib(n-1) + rFib(n-2));
}

int iFib(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;

    int pp = 0;
    int p = 1;
    int result = 0;

    for(int i = 2; i <= n; i++) {
        result = p + pp;
        pp = p;
        p = result;
    }
}

int main(void) {
    int n;
     scanf("%d", &n);
     printf("%d %d %d\n", count, rFib(n), iFib(n));

     return 0;
}