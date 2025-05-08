#include "LUT/lut.h"
#include <stddef.h>
#include <stdio.h>

int main()
{
    printf("%p\n", LUT_len);
    printf("%p\n", LUT_len[0]);
    if (LUT_len[0] == NULL)
    {
        printf("what the fuck!!!!!!!!!\n");
    }
    else
    {
        printf("lmao as if\n");
    }
}
