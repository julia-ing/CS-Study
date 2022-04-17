#include <stdio.h>
#include <stdlib.h>

int fractionalKnapsack(int n, int w[], int v[], int c) {
    int wSum, vSum = 0;
    int i = 0;
    for(i = 0; i < n; i++) {
        if (wSum + w[i] <= c) {
            wSum = wSum + w[i];
            vSum = vSum + v[i];
        }
        else break;
    }
    
    if (c - wSum > 0)
        vSum = vSum + (c - wSum) * v[i] / w[i];
        
    return vSum;
}

int main()
{
    int S[2][4] = {
        {10, 15, 25, 80},
        {60000, 50000, 4000, 1000}
    };
    
    printf("%d ", fractionalKnapsack(4, S[0], S[1], 40));
    
    return 0;
}
