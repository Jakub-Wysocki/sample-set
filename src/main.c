#include <stdio.h>
#include "buff_ring.h"

int main()
{

    buff_ring_struct sample_ring_buffer;

    buff_ring_init(&sample_ring_buffer);

    for (int i = 0; i < 130; i++)
    {
        buff_ring_push(&sample_ring_buffer, i);
    }

    int temp;
    for (int i = 0; i < 130; i++)
    {
        buff_ring_pop(&sample_ring_buffer, &temp);
        printf("%d ", temp);
    }

    return 0;
}