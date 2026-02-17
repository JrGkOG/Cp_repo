#include <stdio.h>

int main()
{
    long long sum = 0;

    for(int i = 0; i < 9000000; i++)
    {
        int unusedA = 300;
        int unusedB = unusedA + 200;

        int used = 88;

        sum = sum + used;
    }

    printf("Used sum: %lld\n", sum);

    return 0;
}
