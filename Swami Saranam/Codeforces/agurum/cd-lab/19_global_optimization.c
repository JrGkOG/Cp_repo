#include <stdio.h>

int globalVal = 75;

int main()
{
    long long sum = 0;

    for(int i = 0; i < 9000000; i++)
    {
        sum = sum + globalVal;
    }

    printf("Global sum: %lld\n", sum);

    return 0;
}

