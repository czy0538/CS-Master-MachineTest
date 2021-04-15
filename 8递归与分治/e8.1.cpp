#include <cstdio>

int find(int line, int n);

int main(void)
{
    int i, j, temp, n;
    printf("How many line:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < n - i; j++)
            printf("\t");

        for (j = 1; j <= i; j++)
        {
            temp = find(i, j);
            printf("%d\t\t", temp);
        }
        printf("\n");
    }
    return 0;
}

int find(int line, int n)
{
    int num;
    if (n > line)
        return 0;
    else if (n == 1)
        return 1;
    else
    {
        num = find(line - 1, n - 1) + find(line - 1, n);
        return num;
    }
    return 0;
