/* main1.c */
#include <stdio.h>

/* define external functions */
extern void util_file();
extern void util_net();
extern void util_math();
extern void util_power(int base, int power);
extern unsigned int gcd(unsigned int u, unsigned int v);

int main()
{
    printf("Inside main()\n");

    /* use a function from each object file that is in the library */
    util_file();
    util_net();
    util_math();
    util_power(2, 3);
    printf("gcd(48, 18) = %u\n", gcd(48, 18));
    return 0;
}
