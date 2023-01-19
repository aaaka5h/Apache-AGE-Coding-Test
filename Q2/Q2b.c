// Memoized method
#include <stdio.h>
#include <stdlib.h>

int memoF(int n, int dp[]) {
    if (n <= 2) return n;
    if (dp[n] > 0) return dp[n];
    dp[n] = memoF(n-3, dp) + memoF(n-2, dp);
    return dp[n];
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    int dp[n+1];
    for (int i=0; i<n+1; i++) {
        dp[i] = -1;
    }
    printf("%i\n", memoF(n, dp));
    return 0;
}