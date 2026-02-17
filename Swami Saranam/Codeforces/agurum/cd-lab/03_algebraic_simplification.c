#include <stdio.h>

int main()
{
    long long aggregate = 0;

    int idx = 0;

    while(idx < 9000000)
    {
        int fixed = 55;

        int simplified = fixed * 1 + 0 - 0 + (10 - 10) / 1;

        aggregate = aggregate + simplified;

        idx = idx + 1;
    }

    printf("Output value: %lld\n", aggregate);

    return 0;
}
