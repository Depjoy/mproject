#include <stdlib.h>
#include <stdint.h>
/*
    Get the number of '1' in value
*/
int num_one_bits(unsigned value)
{
    uint8_t ones = 0;
    for(;value != 0;value >>= 1){
        if(value & 0x01)
            ones += 1;
    }

    return ones;
}
