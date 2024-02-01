#include <stdio.h>

int countDigits(int n, int count) {
    return (n == 0) ? count : countDigits(n / 10, count + 1);
}

int main() {
    int number, digitCount;
    printf("Enter a number: ");
    scanf("%d", &number);
    digitCount = countDigits((number < 0) ? -number : number, 0);
    printf("Number of digits: %d\n", digitCount);
    return 0;
}
