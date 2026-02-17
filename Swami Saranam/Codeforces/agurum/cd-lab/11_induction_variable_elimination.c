#include <stdio.h>

int main()
{
    long long sum = 0;

    int j = 0;

    for(int i = 0; i < 7000000; i++)
    {
        j = i * 3;

        sum = sum + j;
    }

    printf("Induction sum: %lld\n", sum);

    return 0;
}
