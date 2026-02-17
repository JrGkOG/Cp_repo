#include <stdio.h>

int main()
{
    long long collector = 0;

    int position = 0;

    while(position < 7000000)
    {
        int core = 18;

        int computedValue = core * 8 * 2;

        collector = collector + computedValue;

        position = position + 1;
    }

    printf("Final result: %lld\n", collector);

    return 0;
}
