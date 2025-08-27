#ifndef __BUFF_RING_H__
#define __BUFF_RING_H__

#include <stdint.h>
#include <string.h>

#define SIZE 128

typedef enum
{
    BUFF_OK = 0,
    BUFF_EMPTY,
    BUFF_FULL,
    BUFF_ERROR
} BUFF_RING_STATUS;

typedef struct buff_ring_struct
{
    uint32_t head;
    uint32_t tail;
    uint32_t data[SIZE];
    uint32_t ctr;
} buff_ring_struct;

buff_ring_struct *buff_ring_init(buff_ring_struct *buff_ring);
BUFF_RING_STATUS buff_ring_push(buff_ring_struct *buff_ring, uint32_t value);
BUFF_RING_STATUS buff_ring_pop(buff_ring_struct *buff_ring, uint32_t *value);

#endif