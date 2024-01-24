#include <stdio.h>

void hanoi(int n, char s, char d, char a, int *step) {
    if (n) {
        hanoi(n-1, s, a, d, step);
        (*step)++;
        printf("Step %d: Move ring %d from %c to %c\n", *step, n, s, d);
        hanoi(n-1, a, d, s, step);
    }
}

int main() {
    int n;
    printf("Enter the number of rings: ");
    scanf("%d", &n);
    int step = 0;
    hanoi(n, 'A', 'C', 'B', &step);
    return 0;
}
