#include <stdio.h>

int process(int x, int y)
{
    return (x*x + y*y) * (x+y);
}

int main()
{
    long long total = 0;

    for(int i = 0; i < 5000000; i++)
    {
        total += process(3,4);
        total += process(6,7);
    }

    printf("Clone total: %lld\n", total);

    return 0;
}

