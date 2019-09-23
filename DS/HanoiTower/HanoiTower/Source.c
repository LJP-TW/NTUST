#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hanoi(int n, int source, int temp, int target)
{
    if (n == 1)
    {
        printf("Move disk %d From tower %d to tower %d\n", n, source, target);
    }
    else
    {
        hanoi(n - 1, source, target, temp);
        printf("Move disk %d From tower %d to tower %d\n", n, source, target);
        hanoi(n - 1, temp, source, target);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    hanoi(n, 2, 3, 1);
    system("pause");
    return 0;
}