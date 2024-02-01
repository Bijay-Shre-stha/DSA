#include <stdio.h>

void hanoi(int n, char s, char a, char d) {
    if (n == 1) printf("Move disk 1 from %c to %c\n", s, d);
    else { hanoi(n-1, s, d, a); printf("Move disk %d from %c to %c\n", n, s, d); hanoi(n-1, a, s, d); }
}

int main() {
    printf("Tower of Hanoi for 4 disks:\n");
    hanoi(4, 'A', 'B', 'C');

    printf("\nTower of Hanoi for 5 disks:\n");
    hanoi(5, 'A', 'B', 'C');

    return 0;
}
