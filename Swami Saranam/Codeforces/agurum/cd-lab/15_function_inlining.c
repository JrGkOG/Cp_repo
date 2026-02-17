#include <stdio.h>

int compute(int x)
{
    return x * 4 + 6;
}

int main()
{
    long long result = 0;

    for(int i = 0; i < 8000000; i++)
    {
        result = result + compute(25);
    }

    printf("Inline result: %lld\n", result);

    return 0;
}
