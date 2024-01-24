#include <stdio.h>

void hanoi(int n, char s, char d, char a) {
    if (n) {
        hanoi(n-1, s, a, d);
        printf("Move disk %d from %c to %c\n", n, s, d);
        hanoi(n-1, a, d, s);
    }
}

int main() {
    int n;
    printf("Enter the number of rings: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
