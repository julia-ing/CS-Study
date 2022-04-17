#include <stdio.h>
#define N 4

int memo[N][N] = {0};

int getMax(int a, int b, int c) {
    if(a > b) {
        if (a > c)
            return a;
        return c; 
    }
    else {
        if (b > c)
            return b;
        return c;
    }
}

// 재귀
int maxRecur(int cost[N][N], int rowIdx, int colIdx){
    if(rowIdx == 0 && colIdx == 0)
        return cost[0][0];
    if(rowIdx == 0)
        return maxRecur(cost, 0, colIdx-1) + cost[0][colIdx];
    if(colIdx == 0)
        return maxRecur(cost, rowIdx-1, 0) + cost[rowIdx][0];
    
    int left = maxRecur(cost, rowIdx, colIdx-1);
    int up = maxRecur(cost, rowIdx-1, colIdx);
    int leftUp = maxRecur(cost, rowIdx-1, colIdx-1);
    
    return getMax(left, up, leftUp) + cost[rowIdx][colIdx];
}

// 메모이제이션
int maxMemo(int cost[N][N], int rowIdx, int colIdx){
    if (memo[rowIdx][colIdx] != 0)
        return memo[rowIdx][colIdx];
        
    else if(rowIdx == 0 && colIdx == 0)
        memo[rowIdx][colIdx] = cost[0][0];
        
    else if(rowIdx == 0)
        memo[rowIdx][colIdx] = maxMemo(cost, 0, colIdx-1) + cost[0][colIdx];
        
    else if(colIdx == 0)
        memo[rowIdx][colIdx] = maxMemo(cost, rowIdx-1, 0) + cost[rowIdx][0];
    
    else {
        int left = maxMemo(cost, rowIdx, colIdx-1);
        int up = maxMemo(cost, rowIdx-1, colIdx);
        int leftUp = maxMemo(cost, rowIdx-1, colIdx-1);
        
        memo[rowIdx][colIdx] = getMax(left, up, leftUp) + cost[rowIdx][colIdx];
    }
    return memo[rowIdx][colIdx];
}

// 동적 계획
int maxDP(int cost[N][N]){
    
    memo[0][0] = cost[0][0];
    
    for(int row = 0; row < N; row++)
        memo[row][0] = memo[row-1][0] + cost[row][0];
        
    for(int col = 0; col < N; col++)
        memo[0][col] = memo[0][col-1] + cost[0][col];
        
    for(int i = 1; i < N; i++) 
        for(int j = 1; j < N; j++)
            memo[i][j] = getMax(memo[i][j-1], memo[i-1][j], memo[i-1][j-1]) + cost[i][j];
            
    return memo[N-1][N-1];
}

void printMatrix(int cost[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            printf("%2d ", cost[i][j]);
        printf("\n");
    }
}

int main()
{
    int cost[N][N] = {
        {3,-2,1,4},
        {-1,2,-3,4},
        {2,1,4,3},
        {-2,6,-4,2}
    };
    
    printf("%d\n", maxRecur(cost, 3, 3));
    printf("%d\n", maxMemo(cost, 3, 3));
    printf("%d\n", maxDP(cost));
    printMatrix(memo);

    return 0;
}
