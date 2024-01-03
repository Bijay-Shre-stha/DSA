#include<stdio.h>
int max(int a , int b){
    return (a > b) ? a : b;
}
int min(int a , int b){
    return (a < b) ? a : b;
}

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Max: %d\n", max(a, b));
    printf("Min: %d\n", min(a, b));
    
    return 0;
}
