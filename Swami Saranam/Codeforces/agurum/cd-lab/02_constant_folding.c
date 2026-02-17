#include <stdio.h>

int main()
{
    long long aggregate = 0;

    int index = 0;

    while(index < 9000000)
    {
        int fixedValue = (9 * 6) + (20 - 5);

        aggregate = aggregate + fixedValue;

        index = index + 1;
    }

    printf("Computed total: %lld\n", aggregate);

    return 0;
}
