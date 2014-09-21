#include <limits.h>
#include <stdio.h>

main(void)
{
    printf("signed char min:%d\n", SCHAR_MIN);
    printf("signed char max:%d\n", SCHAR_MAX);
    printf("int max:%d\n", INT_MAX);
    printf("int min:%d\n", INT_MIN);
    printf("long max:%dl\n", LONG_MAX);
    printf("long min:%dl\n", LONG_MIN);
    printf("short max:%d\n", SHRT_MAX);
    printf("short min:%d\n", SHRT_MIN);

    printf("unsigned char max:%u\n",UCHAR_MAX);
    printf("unsigned int max:%u\n", UINT_MAX);
    printf("unsigned long max:%ul\n", ULONG_MAX);
    printf("unsigned short max:%u\n", USHRT_MAX);

}
