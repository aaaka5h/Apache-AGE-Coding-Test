// Iterative method
#include <stdio.h>
#include <stdlib.h>

int F(int n) {
    if (n <=2) return n;
    int prev3 = 0;
    int prev2 = 1;
    int prev1 = 2;
    int curr;
    for (int i=3; i<=n; i++) {
        curr = prev3 + prev2;
        prev3 = prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }
    
    printf("%i\n", F(atoi(argv[1])));
    return 0;
}