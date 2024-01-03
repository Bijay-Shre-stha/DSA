#include <stdio.h>

unsigned long long factorial(int n) {
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

int main() {
    int number;
    printf("Enter a non-negative integer: ");
    scanf("%d", &number);

    printf("Factorial of %d = %llu\n", number,  factorial(number) );

    return 0;
}
