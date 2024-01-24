#include <stdio.h>

int fibonacci(int n, int a, int b) {
    return (n == 0) ? a : fibonacci(n - 1, b, a + b);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
    } else {
        printf("The %dth term in the Fibonacci series is: %d\n", n, fibonacci(n, 0, 1));
    }

    return 0;
}
