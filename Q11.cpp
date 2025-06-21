#include <stdio.h>
#include <math.h>
#include <stdint.h>
double factorial(int n) {
    double result = 1;
    for(int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
int main() {
    double total_keys = factorial(25);
    printf("Total possible keys (ignoring identical results):\n");
    printf("%.3e (approximately 2^%.1f)\n", total_keys, log2(total_keys));
    double unique_keys = factorial(25) / (2.0 * factorial(4)); 
    printf("\nEffectively unique keys (considering identical results):\n");
    printf("%.3e (approximately 2^%.1f)\n", unique_keys, log2(unique_keys));
    return 0;
}
