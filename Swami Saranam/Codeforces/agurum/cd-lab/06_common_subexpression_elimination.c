#include <stdio.h>

int main()
{
    long long total = 0;

    for(int i = 0; i < 6000000; i++)
    {
        int a = 11;
        int b = 9;

        int expr1 = a * b;
        int expr2 = a * b;
        int expr3 = (a + b) * (a + b);

        total = total + expr1 + expr2 + expr3;
    }

    printf("Total value: %lld\n", total);

    return 0;
}
