#include <stdio.h>

int main()
{
    long long sum = 0;

    for(int i = 0; i < 8000000; i++)
    {
        int val = 45;

        val = val + 0;
        val = val * 1;

        sum = sum + val;
    }

    printf("Peephole sum: %lld\n", sum);

    return 0;
}
