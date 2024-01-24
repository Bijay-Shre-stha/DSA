#include <stdio.h>

long factorial(int n, long result) {
    return (n < 2) ? result : factorial(n - 1, n * result);
}

int main() {
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    long result = (n < 0) ? 0 : factorial(n, 1);

    printf((n < 0) ? "Invalid input. Please enter a non-negative integer.\n" : "The factorial of %d is: %ld\n", n, result);

    return 0;
}
