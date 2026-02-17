#include <stdio.h>

int main()
{
    long long sum1 = 0;
    long long sum2 = 0;

    for(int i = 0; i < 6000000; i++)
    {
        sum1 = sum1 + i;
    }

    for(int i = 0; i < 6000000; i++)
    {
        sum2 = sum2 + i * 2;
    }

    printf("Fusion result: %lld %lld\n", sum1, sum2);

    return 0;
}
