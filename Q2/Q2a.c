// Simple recursive method
#include <stdio.h>
#include <stdlib.h>

int F(int n) {
    return n <=2 ? n : F(n-3) + F(n-2);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }
    printf("%i\n", F(atoi(argv[1])));
    return 0;
}