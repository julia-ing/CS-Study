// 백준 RGB 문제 c언어 연습용.. 
#include <stdio.h>
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define N 6

int memo[N][3] = {0};

int getMin(int a, int b, int c) {
    if(a<b) {
        if(a<c) return a;
        else return c;
    }
    else {
        if(b<c) return b;
        else return c;
    }
}

int RGB(int A[N][3]) {

    for(int i = 0; i < 3; i++) memo[0][i] = A[0][i];

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            memo[i][0] = MIN(memo[i-1][1], memo[i-1][2]) + A[i][0];
            memo[i][1] = MIN(memo[i-1][0], memo[i-1][2]) + A[i][1];
            memo[i][2] = MIN(memo[i-1][0], memo[i-1][1]) + A[i][2];
        }
     }

    return getMin(memo[N-1][0], memo[N-1][1], memo[N-1][2]);
}

int main()
{
    int A[N][3] = {
        {30, 19, 5},
        {64, 77, 64},
        {15, 19, 97},
        {4, 71, 57},
        {90, 86, 84},
        {93, 32, 91},
    };

    printf("%d\n", RGB(A));

    return 0;
}
