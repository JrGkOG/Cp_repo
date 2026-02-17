#include <stdio.h>

int main()
{
    long long sum = 0;

    int invariant = 60;

    for(int i = 0; i < 8500000; i++)
    {
        int value = invariant * 4;

        sum = sum + value;
    }

    printf("Loop sum: %lld\n", sum);

    return 0;
}
