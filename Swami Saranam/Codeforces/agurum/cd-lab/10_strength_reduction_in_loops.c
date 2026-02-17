#include <stdio.h>

int main()
{
    long long total = 0;

    for(int i = 0; i < 8000000; i++)
    {
        int val = i * 5;

        total = total + val;
    }

    printf("Total: %lld\n", total);

    return 0;
}

