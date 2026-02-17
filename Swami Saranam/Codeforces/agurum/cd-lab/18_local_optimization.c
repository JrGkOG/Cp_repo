#include <stdio.h>

int main()
{
    long long total = 0;

    for(int i = 0; i < 8500000; i++)
    {
        int a = 16;
        int b = 4;

        int c = a + b;

        total = total + c;
    }

    printf("Local total: %lld\n", total);

    return 0;
}

