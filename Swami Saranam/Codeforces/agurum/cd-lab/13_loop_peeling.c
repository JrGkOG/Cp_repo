#include <stdio.h>

int main()
{
    long long total = 0;

    for(int i = 1; i <= 8000000; i++)
    {
        total = total + i;
    }

    printf("Total: %lld\n", total);

    return 0;
}
