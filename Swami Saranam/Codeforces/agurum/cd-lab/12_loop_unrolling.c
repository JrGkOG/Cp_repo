#include <stdio.h>

int main()
{
    long long sum = 0;

    for(int i = 0; i < 7500000; i++)
    {
        sum = sum + i;
    }

    printf("Unrolled sum: %lld\n", sum);

    return 0;
}
