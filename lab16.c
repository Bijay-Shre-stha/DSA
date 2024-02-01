#include <stdio.h>

void fibonacciTailRecursion(int n, int a, int b) {
    if (n <= 0) return;
    printf("%d, ", a);
    fibonacciTailRecursion(n - 1, b, a + b);
}

int main() {
    int n;
    printf("Enter the number for Fibonacci series: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }

    printf("Fibonacci series up to %d: ", n);
    fibonacciTailRecursion(n, 0, 1);

    return 0;
}
