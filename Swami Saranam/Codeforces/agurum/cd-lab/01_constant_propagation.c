#include <stdio.h>

int main()
{
    long long accumulator = 0;

    int counter = 0;

    while(counter < 8000000)
    {
        int baseValue = 30;
        int computed = baseValue + 20;

        accumulator = accumulator + computed;

        counter = counter + 1;
    }

    printf("Final value: %lld\n", accumulator);

    return 0;
}
