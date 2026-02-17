#include <stdio.h>

int helper(int x)
{
    return x + 30;
}

int main()
{
    long long sum = 0;

    for(int i = 0; i < 8000000; i++)
    {
        sum = sum + helper(20);
    }

    printf("IPO sum: %lld\n", sum);

    return 0;
}

