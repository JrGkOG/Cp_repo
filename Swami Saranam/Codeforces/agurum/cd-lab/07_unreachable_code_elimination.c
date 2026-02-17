#include <stdio.h>

int main()
{
    long long result = 0;

    for(int i = 0; i < 8000000; i++)
    {
        int val = 90;

        result = result + val;

        if(i < 0)
        {
            result = result + 500;
        }
    }

    printf("Reachable result: %lld\n", result);

    return 0;
}
