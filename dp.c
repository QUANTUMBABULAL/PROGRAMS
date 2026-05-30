// 0/1 Knapsack using dynamic programming
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int dpKnapsack(int w[], int p[], int n, int W) {
    int dp[n+1][W+1];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= W; j++) {

            if(i == 0 || j == 0)
                dp[i][j] = 0;

            else if(w[i-1] <= j)
                dp[i][j] = max(dp[i-1][j],
                               dp[i-1][j-w[i-1]] + p[i-1]);

            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}

int main(void) {
    int w[] = {1, 3, 4, 5};
    int p[] = {1, 4, 5, 7};
    int n = sizeof(w) / sizeof(w[0]);
    int W = 7;

    int result = dpKnapsack(w, p, n, W);
    printf("Maximum Profit = %d\n", result);

    return 0;
}