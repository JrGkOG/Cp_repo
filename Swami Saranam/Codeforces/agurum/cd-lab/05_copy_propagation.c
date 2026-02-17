#include <stdio.h>

int main()
{
    long long storage = 0;

    int iterator = 0;

    while(iterator < 8500000)
    {
        int primary = 64;

        int duplicate1 = primary;

        int duplicate2 = duplicate1;

        int finalValue = duplicate2 + 36;

        storage = storage + finalValue;

        iterator = iterator + 1;
    }

    printf("Stored value: %lld\n", storage);

    return 0;
}
