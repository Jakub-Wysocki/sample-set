#include <stdio.h>
#include "buff_ring.h"
#include <assert.h>

int parity_bit(int32_t data);

int main()
{
    return 0;
}

int parity_bit(int32_t data)
{
    int ctr = 0;
    for (int i = 0; i < 32; i++)
    {
        if (((data >> i) & 1) != 0)
            ctr ^= 1;
            
    }

    return ctr;
}