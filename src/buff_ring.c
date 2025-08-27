#include "buff_ring.h"
#include <stdio.h>

buff_ring_struct *buff_ring_init(buff_ring_struct *buff_ring)
{
    buff_ring->ctr = 0;
    buff_ring->head = 0;
    buff_ring->tail = 0;

    memset(buff_ring->data, 0, SIZE * sizeof(uint32_t));

    return buff_ring;
}

BUFF_RING_STATUS buff_ring_push(buff_ring_struct *buff_ring, uint32_t value)
{
    if (!buff_ring)
        return BUFF_ERROR;

    if (buff_ring->ctr >= SIZE)
        return BUFF_FULL;

    buff_ring->data[buff_ring->head] = value;

    buff_ring->head = (buff_ring->head + 1) & (SIZE - 1);
    buff_ring->ctr++;

    return BUFF_OK;
}

BUFF_RING_STATUS buff_ring_pop(buff_ring_struct *buff_ring, uint32_t *value)
{
    if (!(buff_ring && value))
        return BUFF_ERROR;

    if (!buff_ring->ctr)
        return BUFF_EMPTY;

    *value = buff_ring->data[buff_ring->tail];

    buff_ring->tail = (buff_ring->tail + 1) & (SIZE - 1);
    buff_ring->ctr--;

    return BUFF_OK;
}
